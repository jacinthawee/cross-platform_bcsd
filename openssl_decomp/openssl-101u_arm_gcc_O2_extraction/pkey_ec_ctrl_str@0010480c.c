
int pkey_ec_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = strcmp(param_2,"ec_paramgen_curve");
  if (iVar1 == 0) {
    iVar1 = OBJ_sn2nid(param_3);
    if ((iVar1 == 0) && (iVar1 = OBJ_ln2nid(param_3), iVar1 == 0)) {
      ERR_put_error(0x10,0xc6,0x8d,"ec_pmeth.c",0xfb);
      return 0;
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,2,0x1001,iVar1,(void *)0x0);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}

