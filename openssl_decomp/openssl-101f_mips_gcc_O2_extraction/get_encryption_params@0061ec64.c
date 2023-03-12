
int * get_encryption_params(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int *piVar4;
  
  if (param_1 == 0) {
    pcVar2 = (char *)get_gost_engine_param();
    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
      return (int *)(gost_cipher_list + 0xc);
    }
    iVar1 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pcVar2);
    if (iVar1 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
      return (int *)0x0;
    }
  }
  else {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)();
  }
  if (gost_cipher_list._4_4_ == 0) {
LAB_0061ecd0:
    ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
    return (int *)0x0;
  }
  piVar4 = (int *)gost_cipher_list;
  if (iVar1 == gost_cipher_list._0_4_) {
    puVar3 = gost_cipher_list;
  }
  else {
    do {
      puVar3 = (undefined1 *)(piVar4 + 3);
      if (piVar4[4] == 0) goto LAB_0061ecd0;
      piVar4 = (int *)puVar3;
    } while (iVar1 != *(int *)puVar3);
  }
  return (int *)puVar3;
}

