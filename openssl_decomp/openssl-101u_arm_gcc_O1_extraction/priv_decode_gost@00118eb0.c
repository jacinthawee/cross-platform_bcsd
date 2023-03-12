
void priv_decode_gost(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  uchar *puVar1;
  int iVar2;
  ASN1_INTEGER *ai;
  DSA *key;
  ASN1_OCTET_STRING *a;
  EC_KEY *key_00;
  BIGNUM *prv;
  int *piVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uchar *local_50;
  uchar *local_4c;
  long local_48;
  X509_ALGOR *local_44;
  ASN1_OBJECT *local_40;
  undefined auStack_3c [31];
  undefined local_1d;
  int local_1c;
  
  iVar4 = 0;
  local_40 = (ASN1_OBJECT *)0x0;
  local_1c = __stack_chk_guard;
  local_50 = (uchar *)0x0;
  local_4c = (uchar *)0x0;
  local_48 = 0;
  local_44 = (X509_ALGOR *)0x0;
  iVar2 = PKCS8_pkey_get0(&local_40,&local_50,&local_48,&local_44,param_2);
  if (iVar2 != 0) {
    local_4c = local_50;
    iVar2 = decode_gost_algor_params(param_1,local_44);
    if (iVar2 != 0) {
      if (*local_4c == '\x04') {
        a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_4c,local_48);
        if ((a == (ASN1_OCTET_STRING *)0x0) || (a->length != 0x20)) {
          pBVar5 = (BIGNUM *)0x0;
          ERR_GOST_error(0x84,0x72,"gost_ameth.c",0x13f);
          goto LAB_00118ee6;
        }
        piVar3 = &local_1c;
        do {
          puVar1 = a->data + iVar4;
          iVar4 = iVar4 + 1;
          piVar3 = (int *)((int)piVar3 + -1);
          *(uchar *)piVar3 = *puVar1;
        } while (iVar4 != 0x20);
        ASN1_STRING_free(a);
        prv = (BIGNUM *)getbnfrombuf(auStack_3c,0x20);
      }
      else {
        ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_4c,local_48);
        if (ai == (ASN1_INTEGER *)0x0) goto LAB_00118ee4;
        pBVar5 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
        ASN1_INTEGER_free(ai);
        prv = pBVar5;
        if (pBVar5 == (BIGNUM *)0x0) {
          ERR_GOST_error(0x84,0x72,"gost_ameth.c",0x14e);
          goto LAB_00118ee6;
        }
      }
      iVar2 = EVP_PKEY_base_id(param_1);
      if (iVar2 == 0x32b) {
        key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
        if (key_00 == (EC_KEY *)0x0) {
          key_00 = EC_KEY_new();
          iVar2 = EVP_PKEY_base_id(param_1);
          EVP_PKEY_assign(param_1,iVar2,key_00);
        }
        pBVar5 = (BIGNUM *)EC_KEY_set_private_key(key_00,prv);
        if (pBVar5 != (BIGNUM *)0x0) {
          iVar2 = EVP_PKEY_missing_parameters(param_1);
          if (iVar2 != 0) goto LAB_00118f64;
          pBVar5 = (BIGNUM *)0x1;
          gost2001_compute_public(key_00);
        }
      }
      else {
        if (iVar2 == 0x32c) {
          key = (DSA *)EVP_PKEY_get0(param_1);
          if (key == (DSA *)0x0) {
            key = DSA_new();
            iVar2 = EVP_PKEY_base_id(param_1);
            EVP_PKEY_assign(param_1,iVar2,key);
          }
          pBVar5 = BN_dup(prv);
          *(BIGNUM **)&key->field_0x1c = pBVar5;
          iVar2 = EVP_PKEY_missing_parameters(param_1);
          if (iVar2 == 0) {
            pBVar5 = (BIGNUM *)0x1;
            gost94_compute_public(key);
            goto LAB_00118f66;
          }
        }
LAB_00118f64:
        pBVar5 = (BIGNUM *)0x1;
      }
LAB_00118f66:
      BN_free(prv);
      goto LAB_00118ee6;
    }
  }
LAB_00118ee4:
  pBVar5 = (BIGNUM *)0x0;
LAB_00118ee6:
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar5);
}

