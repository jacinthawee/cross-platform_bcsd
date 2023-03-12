
long PKCS7_ctrl(PKCS7 *p7,int cmd,long larg,char *parg)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if (cmd == 1) {
    if (iVar1 != 0x16) {
      uVar2 = 0x58;
      goto LAB_005a258c;
    }
    p7->detached = larg;
    if (larg != 0) {
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((p7->d).sign)->contents->type);
      if (iVar1 == 0x15) {
        (*(code *)PTR_ASN1_OCTET_STRING_free_006a9e1c)((((p7->d).sign)->contents->d).ptr);
        (((p7->d).sign)->contents->d).ptr = (char *)0x0;
      }
    }
  }
  else {
    if (cmd == 2) {
      if (iVar1 == 0x16) {
        uVar3 = 1;
        if ((p7->d).sign == (PKCS7_SIGNED *)0x0) {
          p7->detached = 1;
        }
        else {
          uVar3 = (uint)((((p7->d).sign)->contents->d).ptr == (char *)0x0);
          p7->detached = uVar3;
        }
        return uVar3;
      }
      uVar2 = 0x67;
LAB_005a258c:
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x68,0x68,"pk7_lib.c",uVar2);
      return 0;
    }
    larg = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x68,0x6e,"pk7_lib.c",0x6d);
  }
  return larg;
}

