
undefined4 __regparm3 do_revoke(X509 *param_1_00,int param_2,undefined4 param_3,undefined4 param_1)

{
  ASN1_TIME *pAVar1;
  uint uVar2;
  X509_NAME *a;
  ASN1_INTEGER *ai;
  BIGNUM *a_00;
  OPENSSL_STRING *ppcVar3;
  int iVar4;
  OPENSSL_STRING pcVar5;
  OPENSSL_STRING *value;
  undefined4 uVar6;
  int in_GS_OFFSET;
  OPENSSL_STRING pcVar7;
  OPENSSL_STRING local_38 [6];
  OPENSSL_STRING local_20 [4];
  
  value = local_38;
  local_20[0] = *(OPENSSL_STRING *)(in_GS_OFFSET + 0x14);
  uVar2 = 0;
  do {
    *(undefined4 *)((int)value + uVar2) = 0;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x18);
  a = X509_get_subject_name(param_1_00);
  local_38[5] = X509_NAME_oneline(a,(char *)0x0,0);
  ai = X509_get_serialNumber(param_1_00);
  a_00 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
  if (a_00 == (BIGNUM *)0x0) {
    uVar6 = 0xffffffff;
  }
  else {
    if (a_00->top == 0) {
      local_38[3] = BUF_strdup("00");
    }
    else {
      local_38[3] = BN_bn2hex(a_00);
    }
    BN_free(a_00);
    if ((local_38[5] != (char *)0x0) && (local_38[3] != (char *)0x0)) {
      ppcVar3 = TXT_DB_get_by_index(*(TXT_DB **)(param_2 + 4),3,value);
      if (ppcVar3 != (OPENSSL_STRING *)0x0) {
        iVar4 = index_name_cmp(value,ppcVar3);
        if (iVar4 == 0) {
          if (**ppcVar3 == 'R') {
            uVar6 = 0xffffffff;
            BIO_printf(bio_err,"ERROR:Already revoked, serial number %s\n",local_38[3]);
          }
          else {
            pcVar7 = ppcVar3[3];
            BIO_printf(bio_err,"Revoking Certificate %s.\n",pcVar7);
            pcVar5 = (OPENSSL_STRING)make_revocation_str(param_3,param_1);
            if (pcVar5 == (OPENSSL_STRING)0x0) {
              uVar6 = 0xffffffff;
              BIO_printf(bio_err,"Error in revocation arguments\n",pcVar7);
            }
            else {
              uVar6 = 1;
              **ppcVar3 = 'R';
              (*ppcVar3)[1] = '\0';
              ppcVar3[2] = pcVar5;
            }
          }
        }
        else {
          uVar6 = 0xffffffff;
          BIO_printf(bio_err,"ERROR:name does not match %s\n",local_38[5]);
        }
        goto LAB_080574df;
      }
      BIO_printf(bio_err,"Adding Entry with serial number %s to DB for %s\n",local_38[3],local_38[5]
                );
      local_38[0] = (OPENSSL_STRING)CRYPTO_malloc(2,"ca.c",0x98c);
      pAVar1 = param_1_00->cert_info->validity->notAfter;
      local_38[1] = (OPENSSL_STRING)CRYPTO_malloc(pAVar1->length + 1,"ca.c",0x98f);
      memcpy(local_38[1],pAVar1->data,pAVar1->length);
      local_38[1][pAVar1->length] = '\0';
      local_38[2] = (OPENSSL_STRING)0x0;
      local_38[4] = (OPENSSL_STRING)CRYPTO_malloc(8,"ca.c",0x996);
      if (((local_38[0] != (OPENSSL_STRING)0x0) && (local_38[1] != (OPENSSL_STRING)0x0)) &&
         (local_38[4] != (char *)0x0)) {
        BUF_strlcpy(local_38[4],"unknown",8);
        *local_38[0] = 'V';
        local_38[0][1] = '\0';
        ppcVar3 = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"ca.c",0x9a4);
        if (ppcVar3 != (OPENSSL_STRING *)0x0) {
          *ppcVar3 = local_38[0];
          local_38[0] = (OPENSSL_STRING)0x0;
          ppcVar3[1] = local_38[1];
          local_38[1] = (OPENSSL_STRING)0x0;
          ppcVar3[2] = local_38[2];
          local_38[2] = (OPENSSL_STRING)0x0;
          ppcVar3[3] = local_38[3];
          local_38[3] = (char *)0x0;
          ppcVar3[4] = local_38[4];
          local_38[4] = (char *)0x0;
          ppcVar3[5] = local_38[5];
          local_38[5] = (char *)0x0;
          ppcVar3[6] = (OPENSSL_STRING)0x0;
          iVar4 = TXT_DB_insert(*(TXT_DB **)(param_2 + 4),ppcVar3);
          if (iVar4 == 0) {
            BIO_printf(bio_err,"failed to update database\n");
            uVar6 = 0xffffffff;
            BIO_printf(bio_err,"TXT_DB error number %ld\n",
                       *(undefined4 *)(*(int *)(param_2 + 4) + 0x10));
          }
          else {
            uVar6 = do_revoke(param_1);
          }
          goto LAB_080574df;
        }
      }
    }
    uVar6 = 0xffffffff;
    BIO_printf(bio_err,"Memory allocation failure\n");
  }
LAB_080574df:
  do {
    if (*value != (OPENSSL_STRING)0x0) {
      CRYPTO_free(*value);
    }
    value = value + 1;
  } while (value != local_20);
  if (local_20[0] == *(OPENSSL_STRING *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

