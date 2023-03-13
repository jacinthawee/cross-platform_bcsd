
undefined4 dh_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  undefined4 uVar2;
  DH *dh;
  ASN1_INTEGER *ai;
  BIGNUM *pBVar3;
  int in_GS_OFFSET;
  uchar *local_28;
  uchar *local_24;
  long local_20;
  int local_1c;
  long *local_18;
  X509_ALGOR *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_28,&local_20,&local_14,param_2);
  if (iVar1 != 0) {
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_1c,&local_18,local_14);
    if (local_1c == 0x10) {
      local_24 = (uchar *)local_18[2];
      dh = d2i_DHparams((DH **)0x0,&local_24,*local_18);
      if (dh == (DH *)0x0) {
        ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x62);
      }
      else {
        ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_28,local_20);
        if (ai == (ASN1_INTEGER *)0x0) {
          ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x67);
        }
        else {
          pBVar3 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          *(BIGNUM **)&dh->field_0x14 = pBVar3;
          if (pBVar3 != (BIGNUM *)0x0) {
            ASN1_INTEGER_free(ai);
            EVP_PKEY_assign(param_1,0x1c,dh);
            uVar2 = 1;
            goto LAB_08110419;
          }
          ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x6d);
          ASN1_INTEGER_free(ai);
        }
        DH_free(dh);
      }
    }
    else {
      ERR_put_error(5,0x6c,0x69,"dh_ameth.c",0x59);
    }
  }
  uVar2 = 0;
LAB_08110419:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

