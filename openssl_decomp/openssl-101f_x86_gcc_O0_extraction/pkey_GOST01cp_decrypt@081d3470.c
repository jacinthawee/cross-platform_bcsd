
undefined4
pkey_GOST01cp_decrypt
          (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 *puVar1;
  EVP_PKEY *pkey;
  int *piVar2;
  EVP_PKEY *peer;
  int iVar3;
  EVP_PKEY *pkey_00;
  int *piVar4;
  EC_KEY *key;
  undefined4 uVar5;
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
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    *param_3 = 0x20;
    uVar5 = 1;
    goto LAB_081d36c1;
  }
  piVar2 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_1090,param_5);
  if (piVar2 == (int *)0x0) {
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xf9);
    uVar5 = 0xffffffff;
    goto LAB_081d36c1;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar2[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (0 < iVar3) goto LAB_081d3517;
    uVar5 = 0;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0x10e);
  }
  else {
    iVar3 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (iVar3 < 1) {
      uVar5 = 0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0x104);
    }
    else {
LAB_081d3517:
      pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
      if (pkey_00 == (EVP_PKEY *)0x0) {
        uVar5 = 0;
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x116);
      }
      else {
        uVar5 = 0;
        iVar3 = get_encryption_params(*(undefined4 *)piVar2[1]);
        if (iVar3 != 0) {
          gost_init(local_108c,*(undefined4 *)(iVar3 + 4));
          piVar4 = *(int **)(piVar2[1] + 8);
          if (*piVar4 != 8) {
            OpenSSLDie("gost2001_keyx.c",0x120,"gkt->key_agreement_info->eph_iv->length==8");
            piVar4 = *(int **)(piVar2[1] + 8);
          }
          local_48 = ((undefined4 *)piVar4[2])[1];
          local_4c = *(undefined4 *)piVar4[2];
          piVar4 = *(int **)*piVar2;
          if (*piVar4 != 0x20) {
            OpenSSLDie("gost2001_keyx.c",0x122,"gkt->key_info->encrypted_key->length==32");
            piVar4 = *(int **)*piVar2;
          }
          puVar1 = (undefined4 *)piVar4[2];
          local_44 = *puVar1;
          local_40 = puVar1[1];
          local_3c = puVar1[2];
          local_38 = puVar1[3];
          local_34 = puVar1[4];
          local_30 = puVar1[5];
          local_2c = puVar1[6];
          local_28 = puVar1[7];
          piVar4 = *(int **)(*piVar2 + 4);
          if (*piVar4 != 4) {
            OpenSSLDie("gost2001_keyx.c",0x124,"gkt->key_info->imit->length==4");
            piVar4 = *(int **)(*piVar2 + 4);
          }
          local_24 = *(undefined4 *)piVar4[2];
          EVP_PKEY_get0(pkey);
          key = (EC_KEY *)EVP_PKEY_get0(pkey_00);
          EC_KEY_get0_public_key(key);
          VKO_compute_key_isra_0(&local_4c);
          uVar5 = 1;
          iVar3 = keyUnwrapCryptoPro(local_108c,local_6c,&local_4c,param_2);
          if (iVar3 == 0) {
            uVar5 = 0;
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",299);
          }
        }
      }
      if (peer == (EVP_PKEY *)0x0) goto LAB_081d36b3;
    }
    EVP_PKEY_free(peer);
  }
LAB_081d36b3:
  GOST_KEY_TRANSPORT_free(piVar2);
LAB_081d36c1:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

