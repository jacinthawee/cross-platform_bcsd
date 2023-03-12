
int priv_decode_gost(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  uchar *puVar1;
  int iVar2;
  ASN1_INTEGER *ai;
  BIGNUM *prv;
  DSA *key;
  BIGNUM *pBVar3;
  ASN1_OCTET_STRING *a;
  EC_KEY *key_00;
  uchar *puVar4;
  int in_GS_OFFSET;
  undefined4 uVar5;
  uchar *local_44;
  uchar *local_40;
  long local_3c;
  X509_ALGOR *local_38;
  ASN1_OBJECT *local_34;
  undefined local_30 [31];
  uchar local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_44 = (uchar *)0x0;
  local_40 = (uchar *)0x0;
  local_3c = 0;
  local_38 = (X509_ALGOR *)0x0;
  local_34 = (ASN1_OBJECT *)0x0;
  iVar2 = PKCS8_pkey_get0(&local_34,&local_44,&local_3c,&local_38,param_2);
  if (iVar2 != 0) {
    local_40 = local_44;
    iVar2 = decode_gost_algor_params();
    if (iVar2 != 0) {
      if (*local_40 == '\x04') {
        a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_40,local_3c);
        if ((a != (ASN1_OCTET_STRING *)0x0) && (a->length == 0x20)) {
          iVar2 = 0;
          puVar4 = &local_11;
          do {
            puVar1 = a->data + iVar2;
            iVar2 = iVar2 + 1;
            *puVar4 = *puVar1;
            puVar4 = puVar4 + -1;
          } while (iVar2 != 0x20);
          ASN1_STRING_free(a);
          prv = (BIGNUM *)getbnfrombuf(local_30,0x20);
          goto LAB_081d8350;
        }
        uVar5 = 0x14f;
LAB_081d83ee:
        ERR_GOST_error(0x84,0x72,"gost_ameth.c",uVar5);
      }
      else {
        ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_40,local_3c);
        if (ai != (ASN1_INTEGER *)0x0) {
          prv = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          ASN1_INTEGER_free(ai);
          if (prv == (BIGNUM *)0x0) {
            uVar5 = 0x162;
            goto LAB_081d83ee;
          }
LAB_081d8350:
          iVar2 = EVP_PKEY_base_id(param_1);
          if (iVar2 == 0x32b) {
            key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
            if (key_00 == (EC_KEY *)0x0) {
              key_00 = EC_KEY_new();
              iVar2 = EVP_PKEY_base_id(param_1);
              EVP_PKEY_assign(param_1,iVar2,key_00);
            }
            iVar2 = EC_KEY_set_private_key(key_00,prv);
            if (iVar2 != 0) {
              iVar2 = EVP_PKEY_missing_parameters(param_1);
              if (iVar2 != 0) goto LAB_081d83a3;
              gost2001_compute_public(key_00);
              iVar2 = 1;
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
              pBVar3 = BN_dup(prv);
              *(BIGNUM **)&key->field_0x1c = pBVar3;
              iVar2 = EVP_PKEY_missing_parameters(param_1);
              if (iVar2 == 0) {
                gost94_compute_public(key);
                iVar2 = 1;
                goto LAB_081d83a8;
              }
            }
LAB_081d83a3:
            iVar2 = 1;
          }
LAB_081d83a8:
          BN_free(prv);
          goto LAB_081d82d4;
        }
      }
    }
  }
  iVar2 = 0;
LAB_081d82d4:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

