
undefined4 ssl_check_srvr_ecc_cert_and_alg(X509 *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  ASN1_OBJECT *o;
  EVP_PKEY *pkey;
  int iVar3;
  undefined4 uVar4;
  int in_GS_OFFSET;
  int line;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = 0;
  local_24 = 0;
  iVar3 = *(int *)(param_2[0x16] + 0x344);
  uVar1 = *(uint *)(iVar3 + 0xc);
  uVar2 = *(uint *)(iVar3 + 0x10);
  if ((*(byte *)(iVar3 + 0x20) & 2) == 0) {
LAB_080c2433:
    X509_check_purpose(param_1,-1,0);
    if ((param_1->sig_alg != (X509_ALGOR *)0x0) &&
       (o = param_1->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
      iVar3 = OBJ_obj2nid(o);
      OBJ_find_sigid_algs(iVar3,&local_28,&local_24);
    }
    if ((uVar1 & 0x60) == 0) {
LAB_080c24b0:
      uVar4 = 1;
      if ((((uVar2 & 0x40) == 0) || ((*(byte *)&param_1->ex_flags & 2) == 0)) ||
         ((*(byte *)&param_1->ex_kusage & 0x80) != 0)) goto LAB_080c24d0;
      line = 0x8ed;
      iVar3 = 0x13e;
    }
    else {
      if (((*(byte *)&param_1->ex_flags & 2) == 0) || ((*(byte *)&param_1->ex_kusage & 8) != 0)) {
        if ((uVar1 & 0x40) == 0) {
          if (((uVar1 & 0x20) != 0) &&
             ((((*param_2 >> 8 != 3 || (*param_2 < 0x303)) && (local_24 != 6)) && (local_24 != 0x13)
              ))) {
LAB_080c2550:
            line = 0x8e3;
            iVar3 = 0x142;
            goto LAB_080c2502;
          }
        }
        else if ((*param_2 >> 8 != 3) || (*param_2 < 0x303)) {
          if (local_24 != 0x198) {
            line = 0x8d9;
            iVar3 = 0x143;
            goto LAB_080c2502;
          }
          if ((uVar1 & 0x20) != 0) goto LAB_080c2550;
        }
        goto LAB_080c24b0;
      }
      line = 0x8d1;
      iVar3 = 0x13d;
    }
LAB_080c2502:
    ERR_put_error(0x14,0x117,iVar3,"ssl_lib.c",line);
  }
  else {
    pkey = X509_get_pubkey(param_1);
    if (pkey != (EVP_PKEY *)0x0) {
      iVar3 = EVP_PKEY_bits(pkey);
      EVP_PKEY_free(pkey);
      if (iVar3 < 0xa4) goto LAB_080c2433;
    }
  }
  uVar4 = 0;
LAB_080c24d0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

