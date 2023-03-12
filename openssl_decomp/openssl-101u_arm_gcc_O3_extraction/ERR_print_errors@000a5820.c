
void ERR_print_errors(BIO *param_1)

{
  ulong uVar1;
  size_t len;
  int iVar2;
  ulong e;
  char *pcVar3;
  char *pcStack_113c;
  char *pcStack_1138;
  int iStack_1134;
  int iStack_1130;
  CRYPTO_THREADID CStack_112c;
  char acStack_1124 [256];
  char acStack_1024 [4096];
  int iStack_24;
  
  iStack_24 = __stack_chk_guard;
  CRYPTO_THREADID_current(&CStack_112c);
  uVar1 = CRYPTO_THREADID_hash(&CStack_112c);
  do {
    e = ERR_get_error_line_data(&pcStack_113c,&iStack_1134,&pcStack_1138,&iStack_1130);
    if (e == 0) break;
    ERR_error_string_n(e,acStack_1124,0x100);
    pcVar3 = pcStack_1138;
    if (-1 < iStack_1130 << 0x1e) {
      pcVar3 = "";
    }
    BIO_snprintf(acStack_1024,0x1000,"%lu:%s:%s:%d:%s\n",uVar1,acStack_1124,pcStack_113c,iStack_1134
                 ,pcVar3);
    len = strlen(acStack_1024);
    iVar2 = BIO_write(param_1,acStack_1024,len);
  } while (0 < iVar2);
  if (iStack_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

