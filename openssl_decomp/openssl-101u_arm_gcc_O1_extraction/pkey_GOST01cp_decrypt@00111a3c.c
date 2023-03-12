
void pkey_GOST01cp_decrypt
               (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
               undefined4 param_5)

{
  EVP_PKEY *pEVar1;
  int *piVar2;
  EVP_PKEY *peer;
  int iVar3;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar4;
  EC_KEY *key;
  EC_POINT *pEVar5;
  void *pvVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 local_109c;
  undefined auStack_1098 [4128];
  undefined auStack_78 [32];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_109c = param_4;
  pEVar1 = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    pEVar4 = (EVP_PKEY *)0x1;
    *param_3 = 0x20;
    goto LAB_00111bc6;
  }
  piVar2 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_109c,param_5);
  if (piVar2 == (int *)0x0) {
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xee);
    pEVar4 = (EVP_PKEY *)0xffffffff;
    goto LAB_00111bc6;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar2[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (0 < iVar3) goto LAB_00111aa4;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0xfe);
    pEVar4 = peer;
  }
  else {
    iVar3 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (iVar3 < 1) {
      pEVar4 = (EVP_PKEY *)0x0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0xf7);
    }
    else {
LAB_00111aa4:
      pkey = EVP_PKEY_CTX_get0_peerkey(param_1);
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x104);
        pEVar4 = pkey;
      }
      else {
        pEVar4 = (EVP_PKEY *)get_encryption_params(*(undefined4 *)piVar2[1]);
        if (pEVar4 != (EVP_PKEY *)0x0) {
          gost_init(auStack_1098,pEVar4->save_type);
          piVar7 = *(int **)(piVar2[1] + 8);
          if (*piVar7 != 8) {
            OpenSSLDie("gost2001_keyx.c",0x10e,"gkt->key_agreement_info->eph_iv->length == 8");
            piVar7 = *(int **)(piVar2[1] + 8);
          }
          local_58 = *(undefined4 *)piVar7[2];
          uStack_54 = ((undefined4 *)piVar7[2])[1];
          piVar7 = *(int **)*piVar2;
          if (*piVar7 != 0x20) {
            OpenSSLDie("gost2001_keyx.c",0x110,"gkt->key_info->encrypted_key->length == 32");
            piVar7 = *(int **)*piVar2;
          }
          puVar8 = (undefined4 *)piVar7[2];
          local_50 = *puVar8;
          uStack_4c = puVar8[1];
          uStack_48 = puVar8[2];
          uStack_44 = puVar8[3];
          uStack_38 = puVar8[6];
          uStack_34 = puVar8[7];
          local_40 = puVar8[4];
          uStack_3c = puVar8[5];
          piVar7 = *(int **)(*piVar2 + 4);
          if (*piVar7 != 4) {
            OpenSSLDie("gost2001_keyx.c",0x112,"gkt->key_info->imit->length == 4");
            piVar7 = *(int **)(*piVar2 + 4);
          }
          local_30 = *(undefined4 *)piVar7[2];
          key = (EC_KEY *)EVP_PKEY_get0(pkey);
          pEVar5 = EC_KEY_get0_public_key(key);
          pvVar6 = EVP_PKEY_get0(pEVar1);
          VKO_compute_key_isra_0(auStack_78,pEVar5,pvVar6,&local_58);
          pEVar1 = (EVP_PKEY *)keyUnwrapCryptoPro(auStack_1098,auStack_78,&local_58,param_2);
          pEVar4 = (EVP_PKEY *)0x1;
          if (pEVar1 == (EVP_PKEY *)0x0) {
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",0x119);
            pEVar4 = pEVar1;
          }
        }
      }
      if (peer == (EVP_PKEY *)0x0) goto LAB_00111bbe;
    }
    EVP_PKEY_free(peer);
  }
LAB_00111bbe:
  GOST_KEY_TRANSPORT_free(piVar2);
LAB_00111bc6:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pEVar4);
  }
  return;
}

