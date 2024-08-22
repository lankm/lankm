if [ -z "$1" ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

nasm -f elf32 -o a.o $1
ld -m elf_i386 -s -o a.exe a.o
rm a.o
./a.exe
rm a.exe
