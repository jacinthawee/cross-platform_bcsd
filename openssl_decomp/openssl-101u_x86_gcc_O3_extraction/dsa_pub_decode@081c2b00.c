
undefined4 dsa_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  undefined4 uVar2;
  DSA *r;
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
      r = d2i_DSAparams((DSA **)0x0,&local_24,*local_18);
      if (r == (DSA *)0x0) {
        ERR_put_error(10,0x75,0x68,"dsa_ameth.c",0x5c);
      }
      else {
LAB_081c2bb7:
        ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_28,local_20);
        if (ai == (ASN1_INTEGER *)0x0) {
          ERR_put_error(10,0x75,0x68,"dsa_ameth.c",0x6b);
        }
        else {
          pBVar3 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          *(BIGNUM **)&r->field_0x18 = pBVar3;
          if (pBVar3 != (BIGNUM *)0x0) {
            ASN1_INTEGER_free(ai);
            EVP_PKEY_assign(param_1,0x74,r);
            uVar2 = 1;
            goto LAB_081c2b39;
          }
          ERR_put_error(10,0x75,0x6c,"dsa_ameth.c",0x70);
          ASN1_INTEGER_free(ai);
        }
        DSA_free(r);
      }
    }
    else if ((local_1c == 5) || (local_1c == -1)) {
      r = DSA_new();
      if (r != (DSA *)0x0) goto LAB_081c2bb7;
      ERR_put_error(10,0x75,0x41,"dsa_ameth.c",0x62);
    }
    else {
      ERR_put_error(10,0x75,0x69,"dsa_ameth.c",0x66);
    }
  }
  uVar2 = 0;
LAB_081c2b39:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

