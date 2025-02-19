'''
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc -c file1.c file2.c main.c
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm file1.o
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm file2.o
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file2
                 U static_var
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm main.o
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc file1.o file2.o main.o -o program
/usr/bin/ld: file2.o:(.data+0x0): multiple definition of `global_var'; file1.o:(.data+0x0): first defined here
/usr/bin/ld: file2.o: warning: relocation against `static_var' in read-only section `.text'
/usr/bin/ld: file2.o: in function `print_from_file2':
file2.c:(.text+0x26): undefined reference to `static_var'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc -c file1.c file2.c main.c
file2.c: In function ‘print_from_file2’:
file2.c:7:44: error: ‘static_var’ undeclared (first use in this function)
    7 | .c -> static_var = %d\n", static_var); // Должна быть ошибка компиляции
      |                           ^~~~~~~~~~

file2.c:7:44: note: each undeclared identifier is reported only once for each function it appears in
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc -c file1.c file2.c main.c
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm file1.o
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm file2.o
                 U global_var
                 U printf
0000000000000000 T print_from_file2
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ nm main.o
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc file1.o file2.o main.o -o program
zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ objdump -t file1.o

file1.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     F .text  0000000000000043 print_from_file1
0000000000000000         *UND*  0000000000000000 printf


zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ objdump -t file2.o

file2.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file2.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  0000000000000027 print_from_file2
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf


zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ objdump -t main.o

main.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 main.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  000000000000003f main
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf
0000000000000000         *UND*  0000000000000000 print_from_file1
0000000000000000         *UND*  0000000000000000 print_from_file2


zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ objdump -x program

program:     file format elf64-x86-64
program
architecture: i386:x86-64, flags 0x00000150:
HAS_SYMS, DYNAMIC, D_PAGED
start address 0x0000000000001060

Program Header:
    PHDR off    0x0000000000000040 vaddr 0x0000000000000040 paddr 0x0000000000000040 align 2**3
         filesz 0x00000000000002d8 memsz 0x00000000000002d8 flags r--
  INTERP off    0x0000000000000318 vaddr 0x0000000000000318 paddr 0x0000000000000318 align 2**0
         filesz 0x000000000000001c memsz 0x000000000000001c flags r--
    LOAD off    0x0000000000000000 vaddr 0x0000000000000000 paddr 0x0000000000000000 align 2**12
         filesz 0x0000000000000628 memsz 0x0000000000000628 flags r--
    LOAD off    0x0000000000001000 vaddr 0x0000000000001000 paddr 0x0000000000001000 align 2**12
         filesz 0x0000000000000201 memsz 0x0000000000000201 flags r-x
    LOAD off    0x0000000000002000 vaddr 0x0000000000002000 paddr 0x0000000000002000 align 2**12
         filesz 0x00000000000001a4 memsz 0x00000000000001a4 flags r--
    LOAD off    0x0000000000002db8 vaddr 0x0000000000003db8 paddr 0x0000000000003db8 align 2**12
         filesz 0x0000000000000260 memsz 0x0000000000000268 flags rw-
 DYNAMIC off    0x0000000000002dc8 vaddr 0x0000000000003dc8 paddr 0x0000000000003dc8 align 2**3
         filesz 0x00000000000001f0 memsz 0x00000000000001f0 flags rw-
    NOTE off    0x0000000000000338 vaddr 0x0000000000000338 paddr 0x0000000000000338 align 2**3
         filesz 0x0000000000000030 memsz 0x0000000000000030 flags r--
    NOTE off    0x0000000000000368 vaddr 0x0000000000000368 paddr 0x0000000000000368 align 2**2
         filesz 0x0000000000000044 memsz 0x0000000000000044 flags r--
0x6474e553 off    0x0000000000000338 vaddr 0x0000000000000338 paddr 0x0000000000000338 align 2**3
         filesz 0x0000000000000030 memsz 0x0000000000000030 flags r--
EH_FRAME off    0x0000000000002074 vaddr 0x0000000000002074 paddr 0x0000000000002074 align 2**2
         filesz 0x0000000000000044 memsz 0x0000000000000044 flags r--
   STACK off    0x0000000000000000 vaddr 0x0000000000000000 paddr 0x0000000000000000 align 2**4
         filesz 0x0000000000000000 memsz 0x0000000000000000 flags rw-
   RELRO off    0x0000000000002db8 vaddr 0x0000000000003db8 paddr 0x0000000000003db8 align 2**0
         filesz 0x0000000000000248 memsz 0x0000000000000248 flags r--

Dynamic Section:
  NEEDED               libc.so.6
  INIT                 0x0000000000001000
  FINI                 0x00000000000011f4
  INIT_ARRAY           0x0000000000003db8
  INIT_ARRAYSZ         0x0000000000000008
  FINI_ARRAY           0x0000000000003dc0
  FINI_ARRAYSZ         0x0000000000000008
  GNU_HASH             0x00000000000003b0
  STRTAB               0x0000000000000480
  SYMTAB               0x00000000000003d8
  STRSZ                0x000000000000008f
  SYMENT               0x0000000000000018
  DEBUG                0x0000000000000000
  PLTGOT               0x0000000000003fb8
  PLTRELSZ             0x0000000000000018
  PLTREL               0x0000000000000007
  JMPREL               0x0000000000000610
  RELA                 0x0000000000000550
  RELASZ               0x00000000000000c0
  RELAENT              0x0000000000000018
  FLAGS                0x0000000000000008
  FLAGS_1              0x0000000008000001
  VERNEED              0x0000000000000520
  VERNEEDNUM           0x0000000000000001
  VERSYM               0x0000000000000510
  RELACOUNT            0x0000000000000003

Version References:
  required from libc.so.6:
    0x09691a75 0x00 03 GLIBC_2.2.5
    0x069691b4 0x00 02 GLIBC_2.34

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .interp       0000001c  0000000000000318  0000000000000318  00000318  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.gnu.property 00000030  0000000000000338  0000000000000338  00000338  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .note.gnu.build-id 00000024  0000000000000368  0000000000000368  00000368  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .note.ABI-tag 00000020  000000000000038c  000000000000038c  0000038c  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .gnu.hash     00000024  00000000000003b0  00000000000003b0  000003b0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .dynsym       000000a8  00000000000003d8  00000000000003d8  000003d8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .dynstr       0000008f  0000000000000480  0000000000000480  00000480  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .gnu.version  0000000e  0000000000000510  0000000000000510  00000510  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .gnu.version_r 00000030  0000000000000520  0000000000000520  00000520  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .rela.dyn     000000c0  0000000000000550  0000000000000550  00000550  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 10 .rela.plt     00000018  0000000000000610  0000000000000610  00000610  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 11 .init         0000001b  0000000000001000  0000000000001000  00001000  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .plt          00000020  0000000000001020  0000000000001020  00001020  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .plt.got      00000010  0000000000001040  0000000000001040  00001040  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 14 .plt.sec      00000010  0000000000001050  0000000000001050  00001050  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 15 .text         00000192  0000000000001060  0000000000001060  00001060  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 16 .fini         0000000d  00000000000011f4  00000000000011f4  000011f4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 17 .rodata       00000073  0000000000002000  0000000000002000  00002000  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 18 .eh_frame_hdr 00000044  0000000000002074  0000000000002074  00002074  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 19 .eh_frame     000000ec  00000000000020b8  00000000000020b8  000020b8  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 20 .init_array   00000008  0000000000003db8  0000000000003db8  00002db8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 21 .fini_array   00000008  0000000000003dc0  0000000000003dc0  00002dc0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 22 .dynamic      000001f0  0000000000003dc8  0000000000003dc8  00002dc8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 23 .got          00000048  0000000000003fb8  0000000000003fb8  00002fb8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 24 .data         00000018  0000000000004000  0000000000004000  00003000  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 25 .bss          00000008  0000000000004018  0000000000004018  00003018  2**0
                  ALLOC
 26 .comment      0000002b  0000000000000000  0000000000000000  00003018  2**0
                  CONTENTS, READONLY
SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000              Scrt1.o
000000000000038c l     O .note.ABI-tag  0000000000000020              __abi_tag
0000000000000000 l    df *ABS*  0000000000000000              crtstuff.c
0000000000001090 l     F .text  0000000000000000              deregister_tm_clones
00000000000010c0 l     F .text  0000000000000000              register_tm_clones
0000000000001100 l     F .text  0000000000000000              __do_global_dtors_aux
0000000000004018 l     O .bss   0000000000000001              completed.0
0000000000003dc0 l     O .fini_array    0000000000000000              __do_global_dtors_aux_fini_array_entry
0000000000001140 l     F .text  0000000000000000              frame_dummy
0000000000003db8 l     O .init_array    0000000000000000              __frame_dummy_init_array_entry
0000000000000000 l    df *ABS*  0000000000000000              file1.c
0000000000004014 l     O .data  0000000000000004              static_var
0000000000000000 l    df *ABS*  0000000000000000              file2.c
0000000000000000 l    df *ABS*  0000000000000000              main.c
0000000000000000 l    df *ABS*  0000000000000000              crtstuff.c
00000000000021a0 l     O .eh_frame      0000000000000000              __FRAME_END__
0000000000000000 l    df *ABS*  0000000000000000              
0000000000003dc8 l     O .dynamic       0000000000000000              _DYNAMIC
0000000000002074 l       .eh_frame_hdr  0000000000000000              __GNU_EH_FRAME_HDR
0000000000003fb8 l     O .got   0000000000000000              _GLOBAL_OFFSET_TABLE_
0000000000000000       F *UND*  0000000000000000              __libc_start_main@GLIBC_2.34
0000000000000000  w      *UND*  0000000000000000              _ITM_deregisterTMCloneTable
0000000000004000  w      .data  0000000000000000              data_start
000000000000118c g     F .text  0000000000000027              print_from_file2
0000000000004018 g       .data  0000000000000000              _edata
00000000000011f4 g     F .fini  0000000000000000              .hidden _fini
0000000000000000       F *UND*  0000000000000000              printf@GLIBC_2.2.5
0000000000004010 g     O .data  0000000000000004              global_var
0000000000004000 g       .data  0000000000000000              __data_start
0000000000000000  w      *UND*  0000000000000000              __gmon_start__
0000000000004008 g     O .data  0000000000000000              .hidden __dso_handle
0000000000002000 g     O .rodata        0000000000000004              _IO_stdin_used
0000000000004020 g       .bss   0000000000000000              _end
0000000000001060 g     F .text  0000000000000026              _start
0000000000001149 g     F .text  0000000000000043              print_from_file1
0000000000004018 g       .bss   0000000000000000              __bss_start
00000000000011b3 g     F .text  000000000000003f              main
0000000000004018 g     O .data  0000000000000000              .hidden __TMC_END__
0000000000000000  w      *UND*  0000000000000000              _ITM_registerTMCloneTable
0000000000000000  w    F *UND*  0000000000000000              __cxa_finalize@GLIBC_2.2.5
0000000000001000 g     F .init  0000000000000000              .hidden _init


zahar@zahar-GL75-9SCK:~/sirius/git/C-practice/task1$ gcc -static file1.c file2.c main.c
'''
