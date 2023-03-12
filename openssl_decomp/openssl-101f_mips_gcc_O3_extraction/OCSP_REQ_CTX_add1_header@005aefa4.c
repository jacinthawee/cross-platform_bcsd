
int OCSP_REQ_CTX_add1_header(OCSP_REQ_CTX *rctx,char *name,char *value)

{
  int iVar1;
  
  if (name == (char *)0x0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)(rctx + 0x10));
  if (0 < iVar1) {
    if (value == (char *)0x0) {
LAB_005af040:
      iVar1 = (*(code *)PTR_BIO_write_006a7f14)(*(undefined4 *)(rctx + 0x10),"\r\n",2);
      return (uint)(iVar1 == 2);
    }
    iVar1 = (*(code *)PTR_BIO_write_006a7f14)(*(undefined4 *)(rctx + 0x10),": ",2);
    if (iVar1 == 2) {
      iVar1 = (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)(rctx + 0x10),value);
      if (0 < iVar1) goto LAB_005af040;
    }
  }
  return 0;
}

