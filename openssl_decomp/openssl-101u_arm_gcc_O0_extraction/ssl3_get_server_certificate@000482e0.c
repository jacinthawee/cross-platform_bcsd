
int ssl3_get_server_certificate(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  X509 *pkey;
  X509 *a;
  X509_ALGOR *pXVar3;
  int iVar4;
  int iVar5;
  X509 *pXVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 uVar9;
  uint len;
  uint uVar10;
  byte *pbVar11;
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
    pbVar7 = *(byte **)(param_1 + 0x40);
    pXVar2 = (X509 *)sk_new_null();
    if (pXVar2 != (X509 *)0x0) {
      uVar10 = (uint)pbVar7[1] << 8 | (uint)*pbVar7 << 0x10 | (uint)pbVar7[2];
      if (uVar10 + 3 == iVar1) {
        if (uVar10 == 0) {
LAB_0004846e:
          iVar1 = ssl_verify_cert_chain(param_1,pXVar2);
          if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
            ERR_clear_error();
            a = (X509 *)ssl_sess_cert_new();
            pkey = a;
            if (a == (X509 *)0x0) goto LAB_00048350;
            iVar1 = *(int *)(param_1 + 0xc0);
            if (*(int *)(iVar1 + 0x98) != 0) {
              ssl_sess_cert_free();
              iVar1 = *(int *)(param_1 + 0xc0);
            }
            *(X509 **)(iVar1 + 0x98) = a;
            a->cert_info = (X509_CINF *)pXVar2;
            pXVar2 = (X509 *)sk_value((_STACK *)pXVar2,0);
            pkey = (X509 *)X509_get_pubkey(pXVar2);
            iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
            if ((*(int *)(iVar1 + 0xc) << 0x1b < 0) && (*(int *)(iVar1 + 0x10) << 0x1a < 0)) {
              pXVar3 = (X509_ALGOR *)ssl_cert_type(pXVar2,pkey);
              iVar1 = *(int *)(param_1 + 0xc0);
              a->signature = (ASN1_BIT_STRING *)0x0;
              pXVar2 = *(X509 **)(iVar1 + 0x9c);
              a->sig_alg = pXVar3;
              if (pXVar2 != (X509 *)0x0) {
                X509_free(pXVar2);
                iVar1 = *(int *)(param_1 + 0xc0);
              }
              *(undefined4 *)(iVar1 + 0x9c) = 0;
LAB_000484f6:
              pXVar2 = (X509 *)0x0;
              a = (X509 *)0x0;
              iVar4 = 1;
              *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
              goto LAB_00048358;
            }
            if ((pkey == (X509 *)0x0) ||
               (pXVar6 = (X509 *)EVP_PKEY_missing_parameters((EVP_PKEY *)pkey),
               pXVar6 != (X509 *)0x0)) {
              pXVar2 = (X509 *)0x0;
              ERR_put_error(0x14,0x90,0xef,"s3_clnt.c",0x4d3);
              pXVar6 = (X509 *)0x0;
              uVar9 = 2;
            }
            else {
              pXVar3 = (X509_ALGOR *)ssl_cert_type(pXVar2,pkey);
              if (-1 < (int)pXVar3) {
                a->sig_alg = pXVar3;
                CRYPTO_add_lock(&pXVar2->references,1,3,"s3_clnt.c",0x4e2);
                if (*(X509 **)(a->sha1_hash + (int)pXVar3 * 0xc + -0x4c) != (X509 *)0x0) {
                  X509_free(*(X509 **)(a->sha1_hash + (int)pXVar3 * 0xc + -0x4c));
                }
                pXVar6 = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
                *(X509 **)(a->sha1_hash + (int)pXVar3 * 0xc + -0x4c) = pXVar2;
                a->signature = (ASN1_BIT_STRING *)(a->sha1_hash + (int)pXVar3 * 0xc + -0x4c);
                if (pXVar6 != (X509 *)0x0) {
                  X509_free(pXVar6);
                }
                CRYPTO_add_lock(&pXVar2->references,1,3,"s3_clnt.c",0x4ee);
                iVar1 = *(int *)(param_1 + 0xc0);
                *(X509 **)(iVar1 + 0x9c) = pXVar2;
                goto LAB_000484f6;
              }
              ERR_put_error(0x14,0x90,0xf7,"s3_clnt.c",0x4dc);
              uVar9 = 2;
              pXVar2 = pXVar6;
            }
          }
          else {
            pkey = (X509 *)0x0;
            uVar9 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
            pXVar6 = (X509 *)0x0;
            ERR_put_error(0x14,0x90,0x86,"s3_clnt.c",0x4a7);
          }
        }
        else {
          if (uVar10 < 3) {
LAB_00048508:
            iVar1 = 0x47d;
          }
          else {
            pbVar11 = pbVar7 + 6;
            len = (uint)pbVar7[4] << 8 | (uint)pbVar7[3] << 0x10 | (uint)pbVar7[5];
            for (uVar8 = len + 3; uVar8 <= uVar10; uVar8 = uVar8 + len + 3) {
              local_24 = pbVar11;
              pXVar6 = d2i_X509((X509 **)0x0,&local_24,len);
              if (pXVar6 == (X509 *)0x0) {
                ERR_put_error(0x14,0x90,0xd,"s3_clnt.c",0x48c);
                uVar9 = 0x2a;
                pkey = pXVar6;
                goto LAB_00048346;
              }
              if (local_24 != pbVar11 + len) {
                pkey = (X509 *)0x0;
                ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",0x492);
                uVar9 = 0x32;
                goto LAB_00048346;
              }
              pkey = (X509 *)sk_push((_STACK *)pXVar2,pXVar6);
              if (pkey == (X509 *)0x0) {
                ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x496);
                a = pXVar6;
                goto LAB_00048350;
              }
              pbVar11 = local_24 + 3;
              if (uVar10 <= uVar8) goto LAB_0004846e;
              if (uVar10 < uVar8 + 3) goto LAB_00048508;
              len = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
            }
            iVar1 = 0x484;
          }
          pXVar6 = (X509 *)0x0;
          ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",iVar1);
          uVar9 = 0x32;
          pkey = pXVar6;
        }
      }
      else {
        pkey = (X509 *)0x0;
        ERR_put_error(0x14,0x90,0x9f,"s3_clnt.c",0x476);
        pXVar6 = (X509 *)0x0;
        uVar9 = 0x32;
      }
      goto LAB_00048346;
    }
    ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x46f);
    a = pXVar2;
    pkey = pXVar2;
  }
  else {
    ERR_put_error(0x14,0x90,0x72,"s3_clnt.c",0x469);
    pXVar6 = (X509 *)0x0;
    uVar9 = 10;
    pkey = (X509 *)0x0;
    pXVar2 = (X509 *)0x0;
LAB_00048346:
    ssl3_send_alert(param_1,2,uVar9);
    a = pXVar6;
  }
LAB_00048350:
  iVar4 = -1;
  *(undefined4 *)(param_1 + 0x34) = 5;
LAB_00048358:
  EVP_PKEY_free((EVP_PKEY *)pkey);
  X509_free(a);
  sk_pop_free((_STACK *)pXVar2,X509_free);
  return iVar4;
}

