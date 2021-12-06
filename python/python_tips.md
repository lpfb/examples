# Listing python installed packages
```sh
pip<version> freeze
```
Where:
- version: could be, for example, 2.7 or 3

# Uninstalling a python package
```sh
sudo pip<version> uninstall <package name>
```

# Using Cython

To compile a python code or even a Cython code with annotate enabled to visualize improvement points, you need to:
```sh
cython -a <python/code code>.py/pyx
```

Cython extension pyx
