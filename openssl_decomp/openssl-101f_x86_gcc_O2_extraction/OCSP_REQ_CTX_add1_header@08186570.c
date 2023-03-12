
int OCSP_REQ_CTX_add1_header(OCSP_REQ_CTX *rctx,char *name,char *value)

{
  int iVar1;
  
  if (name != (char *)0x0) {
    iVar1 = BIO_puts(*(BIO **)(rctx + 0x10),name);
    if (0 < iVar1) {
      if (value == (char *)0x0) {
LAB_081865d6:
        iVar1 = BIO_write(*(BIO **)(rctx + 0x10),"\r\n",2);
        return (uint)(iVar1 == 2);
      }
      iVar1 = BIO_write(*(BIO **)(rctx + 0x10),": ",2);
      if (iVar1 == 2) {
        iVar1 = BIO_puts(*(BIO **)(rctx + 0x10),value);
        if (0 < iVar1) goto LAB_081865d6;
      }
    }
  }
  return 0;
}

