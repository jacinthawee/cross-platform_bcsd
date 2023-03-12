
long PKCS7_ctrl(PKCS7 *p7,int cmd,long larg,char *parg)

{
  int iVar1;
  uint uVar2;
  int line;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (cmd == 1) {
    if (iVar1 == 0x16) {
      p7->detached = larg;
      if (larg == 0) {
        return 0;
      }
      iVar1 = OBJ_obj2nid(((p7->d).sign)->contents->type);
      if (iVar1 != 0x15) {
        return larg;
      }
      ASN1_OCTET_STRING_free((((p7->d).sign)->contents->d).data);
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
      return larg;
    }
    line = 0x58;
    iVar1 = 0x68;
  }
  else if (cmd == 2) {
    if (iVar1 == 0x16) {
      if ((p7->d).sign == (PKCS7_SIGNED *)0x0) {
        uVar2 = 1;
      }
      else {
        uVar2 = (uint)((((p7->d).sign)->contents->d).ptr == (char *)0x0);
      }
      p7->detached = uVar2;
      return uVar2;
    }
    line = 0x67;
    iVar1 = 0x68;
  }
  else {
    line = 0x6d;
    iVar1 = 0x6e;
  }
  ERR_put_error(0x21,0x68,iVar1,"pk7_lib.c",line);
  return 0;
}

