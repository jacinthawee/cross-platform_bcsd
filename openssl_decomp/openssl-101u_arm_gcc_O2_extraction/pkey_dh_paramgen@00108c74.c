
int pkey_dh_paramgen(int param_1,EVP_PKEY *param_2)

{
  DH *dh;
  int iVar1;
  BN_GENCB *cb;
  int *piVar2;
  BN_GENCB BStack_24;
  
  cb = *(BN_GENCB **)(param_1 + 0x1c);
  piVar2 = *(int **)(param_1 + 0x14);
  if (cb != (BN_GENCB *)0x0) {
    cb = &BStack_24;
    evp_pkey_set_cb_translate(cb,param_1);
  }
  dh = DH_new();
  if (dh != (DH *)0x0) {
    iVar1 = DH_generate_parameters_ex(dh,*piVar2,piVar2[1],cb);
    if (iVar1 == 0) {
      DH_free(dh);
      return 0;
    }
    EVP_PKEY_assign(param_2,0x1c,dh);
    return iVar1;
  }
  return 0;
}

