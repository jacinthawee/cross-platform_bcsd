
undefined4 do_revoke(X509 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  X509_NAME *a;
  ASN1_INTEGER *ai;
  BIGNUM *a_00;
  OPENSSL_STRING *ppcVar1;
  int iVar2;
  OPENSSL_STRING pcVar3;
  OPENSSL_STRING *value;
  OPENSSL_STRING **pppcVar4;
  undefined4 uVar5;
  ASN1_TIME *pAVar6;
  OPENSSL_STRING *ppcStack_3c;
  OPENSSL_STRING *local_38 [6];
  
  local_38[0] = (OPENSSL_STRING *)0x0;
  local_38[1] = (OPENSSL_STRING *)0x0;
  local_38[2] = (OPENSSL_STRING *)0x0;
  local_38[3] = (OPENSSL_STRING *)0x0;
  local_38[4] = (OPENSSL_STRING *)0x0;
  local_38[5] = (OPENSSL_STRING *)0x0;
  a = X509_get_subject_name(param_1);
  local_38[5] = (OPENSSL_STRING *)X509_NAME_oneline(a,(char *)0x0,0);
  ai = X509_get_serialNumber(param_1);
  a_00 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
  if (a_00 == (BIGNUM *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    if (a_00->top == 0) {
      local_38[3] = (OPENSSL_STRING *)BUF_strdup("00");
    }
    else {
      local_38[3] = (OPENSSL_STRING *)BN_bn2hex(a_00);
    }
    BN_free(a_00);
    if ((local_38[5] == (OPENSSL_STRING *)0x0) || (local_38[3] == (OPENSSL_STRING *)0x0)) {
      uVar5 = 0xffffffff;
      BIO_printf(bio_err,"Memory allocation failure\n");
    }
    else {
      ppcVar1 = TXT_DB_get_by_index(*(TXT_DB **)(param_2 + 4),3,(OPENSSL_STRING *)local_38);
      if (ppcVar1 == (OPENSSL_STRING *)0x0) {
        BIO_printf(bio_err,"Adding Entry with serial number %s to DB for %s\n",local_38[3],
                   local_38[5]);
        local_38[0] = (OPENSSL_STRING *)CRYPTO_malloc(2,"ca.c",0x93b);
        pAVar6 = param_1->cert_info->validity->notAfter;
        local_38[1] = (OPENSSL_STRING *)CRYPTO_malloc(pAVar6->length + 1,"ca.c",0x93e);
        memcpy(local_38[1],pAVar6->data,pAVar6->length);
        *(undefined *)((int)local_38[1] + pAVar6->length) = 0;
        local_38[2] = ppcVar1;
        local_38[4] = (OPENSSL_STRING *)CRYPTO_malloc(8,"ca.c",0x945);
        if (((local_38[0] != (OPENSSL_STRING *)0x0) && (local_38[1] != (OPENSSL_STRING *)0x0)) &&
           (local_38[4] != (OPENSSL_STRING *)0x0)) {
          BUF_strlcpy((char *)local_38[4],"unknown",8);
          *(undefined *)local_38[0] = 0x56;
          *(undefined *)((int)local_38[0] + 1) = 0;
          value = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"ca.c",0x953);
          if (value != (OPENSSL_STRING *)0x0) {
            *value = (OPENSSL_STRING)local_38[0];
            value[1] = (OPENSSL_STRING)local_38[1];
            value[2] = (OPENSSL_STRING)local_38[2];
            value[3] = (OPENSSL_STRING)local_38[3];
            value[4] = (OPENSSL_STRING)local_38[4];
            value[5] = (OPENSSL_STRING)local_38[5];
            value[6] = (OPENSSL_STRING)0x0;
            local_38[0] = ppcVar1;
            local_38[1] = ppcVar1;
            local_38[2] = ppcVar1;
            local_38[3] = ppcVar1;
            local_38[4] = ppcVar1;
            local_38[5] = ppcVar1;
            iVar2 = TXT_DB_insert(*(TXT_DB **)(param_2 + 4),value);
            if (iVar2 == 0) {
              uVar5 = 0xffffffff;
              BIO_printf(bio_err,"failed to update database\n");
              BIO_printf(bio_err,"TXT_DB error number %ld\n",
                         *(undefined4 *)(*(int *)(param_2 + 4) + 0x10));
            }
            else {
              uVar5 = do_revoke(param_1,param_2,param_3,param_4);
            }
            goto LAB_0001b63e;
          }
        }
        uVar5 = 0xffffffff;
        BIO_printf(bio_err,"Memory allocation failure\n");
      }
      else {
        iVar2 = index_name_cmp(local_38,ppcVar1);
        if (iVar2 == 0) {
          if (**ppcVar1 == 'R') {
            uVar5 = 0xffffffff;
            BIO_printf(bio_err,"ERROR:Already revoked, serial number %s\n",local_38[3]);
          }
          else {
            BIO_printf(bio_err,"Revoking Certificate %s.\n",ppcVar1[3]);
            pcVar3 = (OPENSSL_STRING)make_revocation_str(param_3,param_4);
            if (pcVar3 == (OPENSSL_STRING)0x0) {
              uVar5 = 0xffffffff;
              BIO_printf(bio_err,"Error in revocation arguments\n");
            }
            else {
              uVar5 = 1;
              **ppcVar1 = 'R';
              (*ppcVar1)[1] = '\0';
              ppcVar1[2] = pcVar3;
            }
          }
        }
        else {
          uVar5 = 0xffffffff;
          BIO_printf(bio_err,"ERROR:name does not match %s\n",local_38[5]);
        }
      }
    }
  }
LAB_0001b63e:
  pppcVar4 = &ppcStack_3c;
  do {
    pppcVar4 = pppcVar4 + 1;
    if (*pppcVar4 != (OPENSSL_STRING *)0x0) {
      CRYPTO_free(*pppcVar4);
    }
  } while (pppcVar4 != local_38 + 5);
  return uVar5;
}

