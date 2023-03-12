
int ssl3_get_server_certificate(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  X509 *pkey;
  X509 *pkey_00;
  X509_ALGOR *pXVar3;
  int iVar4;
  int iVar5;
  X509 *pXVar6;
  uint len;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  int local_28;
  byte *local_24;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_28);
  if (local_28 == 0) {
    return iVar1;
  }
  iVar4 = *(int *)(param_1 + 0x58);
  iVar5 = *(int *)(iVar4 + 0x340);
  if ((iVar5 == 0xc) || ((*(int *)(*(int *)(iVar4 + 0x344) + 0x10) << 0x1a < 0 && (iVar5 == 0xe))))
  {
    *(undefined4 *)(iVar4 + 0x354) = 1;
    return 1;
  }
  if (iVar5 == 0xb) {
    pbVar8 = *(byte **)(param_1 + 0x40);
    pXVar2 = (X509 *)sk_new_null();
    if (pXVar2 == (X509 *)0x0) {
      ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x459);
      iVar1 = -1;
      pXVar6 = pXVar2;
      pkey = pXVar2;
      goto LAB_0004b64c;
    }
    uVar11 = (uint)pbVar8[1] << 8 | (uint)*pbVar8 << 0x10 | (uint)pbVar8[2];
    if (uVar11 + 3 == iVar1) {
      if (uVar11 == 0) {
LAB_0004b750:
        iVar1 = ssl_verify_cert_chain(param_1,pXVar2);
        if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
          ERR_clear_error();
          pkey = (X509 *)ssl_sess_cert_new();
          if (pkey == (X509 *)0x0) {
            iVar1 = -1;
            pXVar6 = pkey;
            goto LAB_0004b64c;
          }
          iVar1 = *(int *)(param_1 + 0xc0);
          if (*(int *)(iVar1 + 0x98) != 0) {
            ssl_sess_cert_free();
            iVar1 = *(int *)(param_1 + 0xc0);
          }
          *(X509 **)(iVar1 + 0x98) = pkey;
          pkey->cert_info = (X509_CINF *)pXVar2;
          pXVar2 = (X509 *)sk_value((_STACK *)pXVar2,0);
          pkey_00 = (X509 *)X509_get_pubkey(pXVar2);
          iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
          if ((*(int *)(iVar1 + 0xc) << 0x1b < 0) && (*(int *)(iVar1 + 0x10) << 0x1a < 0)) {
            pXVar3 = (X509_ALGOR *)ssl_cert_type(pXVar2,pkey_00);
            iVar4 = *(int *)(param_1 + 0xc0);
            pkey->signature = (ASN1_BIT_STRING *)0x0;
            pXVar2 = *(X509 **)(iVar4 + 0x9c);
            pkey->sig_alg = pXVar3;
            if (pXVar2 != (X509 *)0x0) {
              X509_free(pXVar2);
              iVar4 = *(int *)(param_1 + 0xc0);
            }
            *(undefined4 *)(iVar4 + 0x9c) = 0;
LAB_0004b7d8:
            pXVar2 = (X509 *)0x0;
            iVar1 = 1;
            *(undefined4 *)(iVar4 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
            pXVar6 = (X509 *)0x0;
            pkey = pkey_00;
            goto LAB_0004b64c;
          }
          if ((pkey_00 == (X509 *)0x0) ||
             (pXVar6 = (X509 *)EVP_PKEY_missing_parameters((EVP_PKEY *)pkey_00),
             pXVar6 != (X509 *)0x0)) {
            pXVar2 = (X509 *)0x0;
            ERR_put_error(0x14,0x90,0xef,"s3_clnt.c",0x4b4);
            pXVar6 = (X509 *)0x0;
            uVar7 = 2;
          }
          else {
            pXVar3 = (X509_ALGOR *)ssl_cert_type(pXVar2,pkey_00);
            if (-1 < (int)pXVar3) {
              pkey->sig_alg = pXVar3;
              CRYPTO_add_lock(&pXVar2->references,1,3,"s3_clnt.c",0x4c5);
              if (*(X509 **)(pkey->sha1_hash + (int)pXVar3 * 0xc + -0x4c) != (X509 *)0x0) {
                X509_free(*(X509 **)(pkey->sha1_hash + (int)pXVar3 * 0xc + -0x4c));
              }
              pXVar6 = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
              *(X509 **)(pkey->sha1_hash + (int)pXVar3 * 0xc + -0x4c) = pXVar2;
              pkey->signature = (ASN1_BIT_STRING *)(pkey->sha1_hash + (int)pXVar3 * 0xc + -0x4c);
              if (pXVar6 != (X509 *)0x0) {
                X509_free(pXVar6);
              }
              CRYPTO_add_lock(&pXVar2->references,1,3,"s3_clnt.c",0x4cf);
              iVar4 = *(int *)(param_1 + 0xc0);
              *(X509 **)(iVar4 + 0x9c) = pXVar2;
              goto LAB_0004b7d8;
            }
            ERR_put_error(0x14,0x90,0xf7,"s3_clnt.c",0x4be);
            uVar7 = 2;
            pXVar2 = pXVar6;
          }
        }
        else {
          pkey_00 = (X509 *)0x0;
          uVar7 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
          pXVar6 = (X509 *)0x0;
          ERR_put_error(0x14,0x90,0x86,"s3_clnt.c",0x48f);
        }
      }
      else {
        pbVar10 = pbVar8 + 6;
        len = (uint)pbVar8[3] << 0x10 | (uint)pbVar8[4] << 8 | (uint)pbVar8[5];
        for (uVar9 = len + 3; uVar9 <= uVar11; uVar9 = uVar9 + len + 3) {
          local_24 = pbVar10;
          pXVar6 = d2i_X509((X509 **)0x0,&local_24,len);
          if (pXVar6 == (X509 *)0x0) {
            ERR_put_error(0x14,0x90,0xd,"s3_clnt.c",0x473);
            uVar7 = 0x2a;
            pkey_00 = pXVar6;
            goto LAB_0004b63e;
          }
          if (local_24 != pbVar10 + len) {
            pkey_00 = (X509 *)0x0;
            ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",0x479);
            uVar7 = 0x32;
            goto LAB_0004b63e;
          }
          pkey = (X509 *)sk_push((_STACK *)pXVar2,pXVar6);
          if (pkey == (X509 *)0x0) {
            iVar1 = -1;
            ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x47e);
            goto LAB_0004b64c;
          }
          pbVar10 = local_24 + 3;
          if (uVar11 <= uVar9) goto LAB_0004b750;
          len = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
        }
        pXVar6 = (X509 *)0x0;
        ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",0x46a);
        uVar7 = 0x32;
        pkey_00 = pXVar6;
      }
    }
    else {
      pkey_00 = (X509 *)0x0;
      ERR_put_error(0x14,0x90,0x9f,"s3_clnt.c",0x461);
      pXVar6 = (X509 *)0x0;
      uVar7 = 0x32;
    }
  }
  else {
    ERR_put_error(0x14,0x90,0x72,"s3_clnt.c",0x452);
    pXVar6 = (X509 *)0x0;
    uVar7 = 10;
    pkey_00 = (X509 *)0x0;
    pXVar2 = (X509 *)0x0;
  }
LAB_0004b63e:
  iVar1 = -1;
  ssl3_send_alert(param_1,2,uVar7);
  pkey = pkey_00;
LAB_0004b64c:
  EVP_PKEY_free((EVP_PKEY *)pkey);
  X509_free(pXVar6);
  sk_pop_free((_STACK *)pXVar2,X509_free);
  return iVar1;
}

