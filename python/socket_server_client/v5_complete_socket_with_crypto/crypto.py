from Crypto.PublicKey import RSA
from Crypto.Cipher import AES, PKCS1_OAEP
from Crypto.Random import get_random_bytes

class crypto():
    def __init__(self, public_key_file, private_key_file, key_size=2048):
        self.public_key_file = public_key_file
        self.private_key_file = private_key_file
        self._private_key = None
        self._public_key = None
        self.key_size = key_size
        self._assimetric_key_gen()

    def _assimetric_key_gen(self):
        keys_found = True

        try:
            key_file = open(self.public_key_file, "r")
            self._public_key = RSA.importKey(key_file.read())
        except FileNotFoundError:
            keys_found = False

        try:
            key_file = open(self.private_key_file, "rb")
            self._private_key = RSA.importKey(key_file.read())
        except FileNotFoundError:
            keys_found = False

        
        if not keys_found:
            key = RSA.generate(self.key_size)
            self._private_key = key
            self._public_key = key.publickey()
            
            priv_key_file = open(self.private_key_file, "wb")
            priv_key_file.write(key.exportKey('PEM'))
            priv_key_file.close()

            pub_key_file = open(self.public_key_file, "wb")
            pub_key_file.write((key.publickey().exportKey('PEM')))
            pub_key_file.close()

    @property
    def public_key(self):
        return self._public_key

    def encrypt_session_key(self, recipient_key, session_key):
        print("Recipient Key: ", recipient_key)
        print("Session Key: ", session_key)
        cipher_rsa = PKCS1_OAEP.new(recipient_key)
        return cipher_rsa.encrypt(session_key)

    def decrypt_session_key(self, enc_session_key):
        cipher_rsa = PKCS1_OAEP.new(self._private_key)
        return cipher_rsa.decrypt(enc_session_key)

    def encrypt_data(self, session_key, plain_text):
        nonce = get_random_bytes(16)
        cipher_aes = AES.new(session_key, AES.MODE_EAX, nonce)
        ciphertext, tag = cipher_aes.encrypt_and_digest(plain_text)
        return nonce, ciphertext, tag

    def decrypt_data(self, nonce, session_key, cipher_text, tag):
        cipher_aes = AES.new(session_key, AES.MODE_EAX, nonce)
        data = None
        try:
            data = cipher_aes.decrypt_and_verify(cipher_text, tag)
        except ValueError as e:
            print(f"Error: {e}")

        return data


def main():
    cp = crypto("pubkey.pm", "privkey.pm", 2048)

    print("================================================================")
    print("                       Session key tests")
    print("================================================================\n")
    plain_session_key = get_random_bytes(16)
    print(f"Session Key plain data: {plain_session_key}, size: {len(plain_session_key)}")
    print("\n")
    cipher_session_key = cp.encrypt_session_key(cp.public_key, plain_session_key)
    print(f"Session Key encrypted: {cipher_session_key}, size: {len(cipher_session_key)}")
    print("\n")
    plain_session_key = cp.decrypt_session_key(cipher_session_key)
    print(f"Session Key decrypted: {plain_session_key}, size: {len(plain_session_key)}")
    

    print("================================================================")
    print("                       Encrypt massage tests")
    print("================================================================\n")
    plain_massage = b"Testando criptografia"
    print(f"Plaintext: {plain_massage}")
    print(f"Plaintext Size: {len(plain_massage)}")
    print(f"\nSession Key: {plain_session_key}")
    nonce, ciphertext, tag = cp.encrypt_data(plain_session_key, plain_massage)
    print(f"\nNonce: {nonce}")
    print(f"Nonce Size: {len(nonce)}")
    print(f"\nCiphertext: {ciphertext}")
    print(f"Ciphertext Size: {len(ciphertext)}")
    print(f"\nTag: {tag}")
    print(f"Tag Size: {len(tag)}")
    print("================================================================\n\n")

    print("================================================================")
    print("                       Decrypt massage tests")
    print("================================================================\n")
    plain_massage = cp.decrypt_data(nonce, plain_session_key, ciphertext, tag) # OK
    #plain_massage = cp.decrypt_data(nonce, plain_session_key, ciphertext, get_random_bytes(16)) # Fail

    if plain_massage is None:
        print("It was not possible to decrypt data")
    else:
        print(f"Plaintext: {plain_massage}")
        print(f"Plaintext Size: {len(plain_massage)}")
        print(f"\nSession Key: {plain_session_key}")
        print(f"\nNonce: {nonce}")
        print(f"Nonce Size: {len(nonce)}")
        print(f"\nCiphertext: {ciphertext}")
        print(f"Ciphertext Size: {len(ciphertext)}")
        print(f"\nTag: {tag}")
        print(f"Tag Size: {len(tag)}")
    print("================================================================\n\n")

if __name__ == "__main__":
    main()