
undefined4
pkey_GOST94cp_decrypt
          (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 *puVar1;
  EVP_PKEY *pEVar2;
  int *piVar3;
  EVP_PKEY *peer;
  int iVar4;
  EVP_PKEY *pEVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_GS_OFFSET;
  undefined4 local_1090;
  undefined local_108c [4128];
  undefined local_6c [32];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_1090 = param_4;
  pEVar2 = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    *param_3 = 0x20;
    uVar7 = 1;
    goto LAB_081d765a;
  }
  piVar3 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_1090,param_5);
  if (piVar3 == (int *)0x0) {
    ERR_GOST_error(0x7a,0x68,"gost94_keyx.c",0xe6);
    uVar7 = 0;
    goto LAB_081d765a;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar3[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar4 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (0 < iVar4) goto LAB_081d74d1;
    ERR_GOST_error(0x7a,0x84,"gost94_keyx.c",0xf4);
  }
  else {
    iVar4 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (iVar4 < 1) {
      ERR_GOST_error(0x7a,0x83,"gost94_keyx.c",0xed);
    }
    else {
LAB_081d74d1:
      pEVar5 = EVP_PKEY_CTX_get0_peerkey(param_1);
      if (pEVar5 == (EVP_PKEY *)0x0) {
        ERR_GOST_error(0x7a,0x78,"gost94_keyx.c",0xfa);
      }
      else {
        iVar4 = get_encryption_params(*(undefined4 *)piVar3[1]);
        if (iVar4 != 0) {
          gost_init(local_108c,*(undefined4 *)(iVar4 + 4));
          piVar6 = *(int **)(piVar3[1] + 8);
          if (*piVar6 != 8) {
            OpenSSLDie("gost94_keyx.c",0x104,"gkt->key_agreement_info->eph_iv->length == 8");
            piVar6 = *(int **)(piVar3[1] + 8);
          }
          local_48 = ((undefined4 *)piVar6[2])[1];
          local_4c = *(undefined4 *)piVar6[2];
          piVar6 = *(int **)*piVar3;
          if (*piVar6 != 0x20) {
            OpenSSLDie("gost94_keyx.c",0x106,"gkt->key_info->encrypted_key->length == 32");
            piVar6 = *(int **)*piVar3;
          }
          puVar1 = (undefined4 *)piVar6[2];
          local_44 = *puVar1;
          local_40 = puVar1[1];
          local_3c = puVar1[2];
          local_38 = puVar1[3];
          local_34 = puVar1[4];
          local_30 = puVar1[5];
          local_2c = puVar1[6];
          local_28 = puVar1[7];
          piVar6 = *(int **)(*piVar3 + 4);
          if (*piVar6 != 4) {
            OpenSSLDie("gost94_keyx.c",0x108,"gkt->key_info->imit->length == 4");
            piVar6 = *(int **)(*piVar3 + 4);
          }
          local_24 = *(undefined4 *)piVar6[2];
          gost_get0_priv_key(pEVar2);
          make_cp_exchange_key();
          iVar4 = keyUnwrapCryptoPro(local_108c,local_6c,&local_4c,param_2);
          if (iVar4 != 0) {
            EVP_PKEY_free(peer);
            GOST_KEY_TRANSPORT_free(piVar3);
            uVar7 = 1;
            goto LAB_081d765a;
          }
          ERR_GOST_error(0x7a,0x66,"gost94_keyx.c",0x10d);
        }
      }
    }
  }
  EVP_PKEY_free(peer);
  GOST_KEY_TRANSPORT_free(piVar3);
  uVar7 = 0xffffffff;
LAB_081d765a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

