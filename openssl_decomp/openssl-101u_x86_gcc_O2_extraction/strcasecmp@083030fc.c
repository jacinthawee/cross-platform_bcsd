
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strcasecmp@@GLIBC_2.0 */
  halt_baddata();
}

