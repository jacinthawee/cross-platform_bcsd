
int ssl3_get_server_certificate(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  X509 *a;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  _STACK **pp_Var8;
  _STACK *p_Var9;
  EVP_PKEY *pkey;
  uint len;
  X509 *pXVar10;
  int in_GS_OFFSET;
  int iVar11;
  _STACK *local_38;
  int local_28;
  byte *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_28);
  if (local_28 == 0) goto LAB_0809abc6;
  iVar11 = *(int *)(param_1 + 0x58);
  iVar3 = *(int *)(iVar11 + 0x340);
  if ((iVar3 == 0xc) ||
     (((*(byte *)(*(int *)(iVar11 + 0x344) + 0x10) & 0x20) != 0 && (iVar3 == 0xe)))) {
    *(undefined4 *)(iVar11 + 0x354) = 1;
    iVar5 = 1;
    goto LAB_0809abc6;
  }
  if (iVar3 == 0xb) {
    pbVar4 = *(byte **)(param_1 + 0x40);
    local_38 = sk_new_null();
    if (local_38 == (_STACK *)0x0) {
      pkey = (EVP_PKEY *)0x0;
      pXVar10 = (X509 *)0x0;
      ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x46f);
      goto LAB_0809ab94;
    }
    uVar7 = (uint)pbVar4[1] << 8 | (uint)*pbVar4 << 0x10 | (uint)pbVar4[2];
    if (iVar5 != uVar7 + 3) {
      iVar11 = 0x476;
      iVar5 = 0x9f;
LAB_0809ad42:
      pkey = (EVP_PKEY *)0x0;
      pXVar10 = (X509 *)0x0;
      ERR_put_error(0x14,0x90,iVar5,"s3_clnt.c",iVar11);
      uVar6 = 0x32;
      goto LAB_0809ab85;
    }
    if (uVar7 != 0) {
      if (uVar7 < 3) {
LAB_0809ae65:
        iVar11 = 0x47d;
        iVar5 = 0x87;
      }
      else {
        pbVar1 = pbVar4 + 6;
        len = (uint)pbVar4[3] << 0x10 | (uint)pbVar4[4] << 8 | (uint)pbVar4[5];
        for (uVar2 = len + 3; uVar2 <= uVar7; uVar2 = len + 3 + uVar2) {
          local_24 = pbVar1;
          pXVar10 = d2i_X509((X509 **)0x0,&local_24,len);
          if (pXVar10 == (X509 *)0x0) {
            pkey = (EVP_PKEY *)0x0;
            ERR_put_error(0x14,0x90,0xd,"s3_clnt.c",0x48c);
            uVar6 = 0x2a;
            goto LAB_0809ab85;
          }
          if (local_24 != pbVar1 + len) {
            pkey = (EVP_PKEY *)0x0;
            ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",0x492);
            uVar6 = 0x32;
            goto LAB_0809ab85;
          }
          iVar5 = sk_push(local_38,pXVar10);
          if (iVar5 == 0) {
            pkey = (EVP_PKEY *)0x0;
            ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x496);
            goto LAB_0809ab94;
          }
          if (uVar7 <= uVar2) goto LAB_0809ad63;
          if (uVar7 < uVar2 + 3) goto LAB_0809ae65;
          len = (uint)*local_24 << 0x10 | (uint)local_24[1] << 8 | (uint)local_24[2];
          pbVar1 = local_24 + 3;
        }
        iVar11 = 0x484;
        iVar5 = 0x87;
      }
      goto LAB_0809ad42;
    }
LAB_0809ad63:
    iVar5 = ssl_verify_cert_chain(param_1,local_38);
    if ((*(int *)(param_1 + 200) != 0) && (iVar5 < 1)) {
      pkey = (EVP_PKEY *)0x0;
      pXVar10 = (X509 *)0x0;
      uVar6 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
      ERR_put_error(0x14,0x90,0x86,"s3_clnt.c",0x4a7);
      goto LAB_0809ab85;
    }
    ERR_clear_error();
    pp_Var8 = (_STACK **)ssl_sess_cert_new();
    if (pp_Var8 == (_STACK **)0x0) {
      pkey = (EVP_PKEY *)0x0;
      pXVar10 = (X509 *)0x0;
      goto LAB_0809ab94;
    }
    iVar5 = *(int *)(param_1 + 0xc0);
    if (*(int *)(iVar5 + 0x98) != 0) {
      ssl_sess_cert_free(*(int *)(iVar5 + 0x98));
      iVar5 = *(int *)(param_1 + 0xc0);
    }
    *(_STACK ***)(iVar5 + 0x98) = pp_Var8;
    *pp_Var8 = local_38;
    pXVar10 = (X509 *)sk_value(local_38,0);
    pkey = X509_get_pubkey(pXVar10);
    iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
    if (((*(byte *)(iVar5 + 0xc) & 0x10) == 0) || ((*(byte *)(iVar5 + 0x10) & 0x20) == 0)) {
      if ((pkey == (EVP_PKEY *)0x0) || (iVar5 = EVP_PKEY_missing_parameters(pkey), iVar5 != 0)) {
        iVar11 = 0x4d3;
        iVar5 = 0xef;
      }
      else {
        p_Var9 = (_STACK *)ssl_cert_type(pXVar10,pkey);
        if (-1 < (int)p_Var9) {
          pp_Var8[1] = p_Var9;
          CRYPTO_add_lock(&pXVar10->references,1,3,"s3_clnt.c",0x4e2);
          if ((X509 *)pp_Var8[(int)p_Var9 * 3 + 3] != (X509 *)0x0) {
            X509_free((X509 *)pp_Var8[(int)p_Var9 * 3 + 3]);
          }
          pp_Var8[(int)p_Var9 * 3 + 3] = (_STACK *)pXVar10;
          pp_Var8[2] = (_STACK *)(pp_Var8 + (int)p_Var9 * 3 + 3);
          a = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
          if (a != (X509 *)0x0) {
            X509_free(a);
          }
          CRYPTO_add_lock(&pXVar10->references,1,3,"s3_clnt.c",0x4ee);
          iVar11 = *(int *)(param_1 + 0xc0);
          *(X509 **)(iVar11 + 0x9c) = pXVar10;
          goto LAB_0809ae41;
        }
        iVar11 = 0x4dc;
        iVar5 = 0xf7;
      }
      pXVar10 = (X509 *)0x0;
      ERR_put_error(0x14,0x90,iVar5,"s3_clnt.c",iVar11);
      local_38 = (_STACK *)0x0;
      uVar6 = 2;
      goto LAB_0809ab85;
    }
    p_Var9 = (_STACK *)ssl_cert_type(pXVar10,pkey);
    pp_Var8[1] = p_Var9;
    iVar11 = *(int *)(param_1 + 0xc0);
    pp_Var8[2] = (_STACK *)0x0;
    if (*(X509 **)(iVar11 + 0x9c) != (X509 *)0x0) {
      X509_free(*(X509 **)(iVar11 + 0x9c));
      iVar11 = *(int *)(param_1 + 0xc0);
    }
    *(undefined4 *)(iVar11 + 0x9c) = 0;
LAB_0809ae41:
    local_38 = (_STACK *)0x0;
    pXVar10 = (X509 *)0x0;
    iVar5 = 1;
    *(undefined4 *)(iVar11 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
  }
  else {
    pkey = (EVP_PKEY *)0x0;
    pXVar10 = (X509 *)0x0;
    ERR_put_error(0x14,0x90,0x72,"s3_clnt.c",0x469);
    local_38 = (_STACK *)0x0;
    uVar6 = 10;
LAB_0809ab85:
    ssl3_send_alert(param_1,2,uVar6);
LAB_0809ab94:
    *(undefined4 *)(param_1 + 0x34) = 5;
    iVar5 = -1;
  }
  EVP_PKEY_free(pkey);
  X509_free(pXVar10);
  sk_pop_free(local_38,X509_free);
LAB_0809abc6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

