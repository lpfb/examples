import ctypes

# import absolute module path
so_file = "/home/lbarros/projects/open-ran/git/hardware_controller/test/am7842_cli/main.so"

# Instantiate module handler
_libc = ctypes.CDLL(so_file)

# ===== Teste 1 =====
# Create function argument and return pytes
_libc.test.restype = ctypes.c_void_p
_libc.test.argtypes = [ctypes.c_char_p]
arg1_char = ctypes.c_char_p(b"Teste ABC")

# Call an external function and pass a string as argument
_libc.test(arg1_char)

# ===== Teste 2 =====
# Create function argument and return pytes
_libc.test_int_pointer_and_return.restype = ctypes.c_int
_libc.test_int_pointer_and_return.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_int)]

arg1_int = ctypes.c_int(100)
arg2_int_pointer = ctypes.c_int()

# Call an external function and pass a string as argument
ret = _libc.test_int_pointer_and_return(arg1_int, ctypes.byref(arg2_int_pointer))

print("Return int value: ", arg2_int_pointer.value)
print("Return value: ", ret)

# ===== Teste 3 =====
# Create function argument and return pytes
# Class com a estrutura do struct criado na lib em C
class skeleton_mystruct(ctypes.Structure):
  _fields_ = [
    ("int_i", ctypes.c_int),
    ("char_c", ctypes.c_char)
  ]

# Create structure object
skel_st = skeleton_mystruct()
skel_st.int_i = 50
skel_st.char_c = b"D"

_libc.test_struct.restype = ctypes.c_void_p
_libc.test_struct.argtypes = [ctypes.Structure]

# Call an external function and pass a string as argument
_libc.test_struct(skel_st)
