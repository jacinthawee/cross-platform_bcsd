
uint ssl_check_srvr_ecc_cert_and_alg(X509 *param_1,int *param_2)

{
  EVP_PKEY *pkey;
  ASN1_OBJECT *o;
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_28;
  int local_24 [2];
  
  local_28 = 0;
  local_24[0] = 0;
  iVar1 = *(int *)(param_2[0x16] + 0x344);
  uVar2 = *(uint *)(iVar1 + 0xc);
  iVar3 = *(int *)(iVar1 + 0x10);
  if (*(int *)(iVar1 + 0x20) << 0x1e < 0) {
    pkey = X509_get_pubkey(param_1);
    if (pkey == (EVP_PKEY *)0x0) {
      return 0;
    }
    iVar1 = EVP_PKEY_bits(pkey);
    EVP_PKEY_free(pkey);
    if (0xa3 < iVar1) {
      return 0;
    }
  }
  X509_check_purpose(param_1,-1,0);
  if ((param_1->sig_alg != (X509_ALGOR *)0x0) &&
     (o = param_1->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
    iVar1 = OBJ_obj2nid(o);
    OBJ_find_sigid_algs(iVar1,&local_28,local_24);
  }
  if ((uVar2 & 0x60) != 0) {
    if (((int)(param_1->ex_flags << 0x1e) < 0) && ((param_1->ex_kusage & 8) == 0)) {
      ERR_put_error(0x14,0x117,0x13d,"ssl_lib.c",0x8f4);
      return 0;
    }
    if (((int)(uVar2 << 0x19) < 0) &&
       (((*param_2 >> 8 != 3 || (*param_2 < 0x303)) && (local_24[0] != 0x198)))) {
      ERR_put_error(0x14,0x117,0x143,"ssl_lib.c",0x8fb);
      return 0;
    }
    if ((((int)(uVar2 << 0x1a) < 0) && ((*param_2 >> 8 != 3 || (*param_2 < 0x303)))) &&
       (local_24[0] != 0x13 && local_24[0] != 6)) {
      ERR_put_error(0x14,0x117,0x142,"ssl_lib.c",0x904);
      return 0;
    }
  }
  if (((iVar3 << 0x19 < 0) && ((int)(param_1->ex_flags << 0x1e) < 0)) &&
     (uVar2 = param_1->ex_kusage & 0x80, uVar2 == 0)) {
    ERR_put_error(0x14,0x117,0x13e,"ssl_lib.c",0x90d);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

