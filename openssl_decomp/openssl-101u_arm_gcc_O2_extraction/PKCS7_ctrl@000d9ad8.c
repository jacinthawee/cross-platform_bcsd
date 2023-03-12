
long PKCS7_ctrl(PKCS7 *p7,int cmd,long larg,char *parg)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (cmd == 1) {
    if (iVar1 != 0x16) {
      ERR_put_error(0x21,0x68,0x68,"pk7_lib.c",0x55);
      return 0;
    }
    p7->detached = larg;
    if ((larg != 0) && (iVar1 = OBJ_obj2nid(((p7->d).sign)->contents->type), iVar1 == 0x15)) {
      ASN1_OCTET_STRING_free((((p7->d).sign)->contents->d).data);
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
  }
  else {
    if (cmd == 2) {
      if (iVar1 == 0x16) {
        if ((p7->d).sign == (PKCS7_SIGNED *)0x0) {
          uVar2 = 1;
        }
        else {
          uVar2 = count_leading_zeroes((((p7->d).sign)->contents->d).ptr);
          uVar2 = uVar2 >> 5;
        }
        p7->detached = uVar2;
        return uVar2;
      }
      ERR_put_error(0x21,0x68,0x68,"pk7_lib.c",99);
      return 0;
    }
    larg = 0;
    ERR_put_error(0x21,0x68,0x6e,"pk7_lib.c",0x69);
  }
  return larg;
}

