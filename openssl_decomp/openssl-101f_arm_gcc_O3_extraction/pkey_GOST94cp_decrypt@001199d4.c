
void pkey_GOST94cp_decrypt
               (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
               undefined4 param_5)

{
  EVP_PKEY *pEVar1;
  int *piVar2;
  EVP_PKEY *peer;
  int iVar3;
  EVP_PKEY *pEVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
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
  
  local_2c = __TMC_END__;
  local_109c = param_4;
  pEVar1 = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    piVar2 = (int *)0x1;
    *param_3 = 0x20;
    goto LAB_00119b40;
  }
  piVar2 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_109c,param_5);
  if (piVar2 == (int *)0x0) {
    ERR_GOST_error(0x7a,0x68,"gost94_keyx.c",0xe8);
    goto LAB_00119b40;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar2[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (0 < iVar3) goto LAB_00119a3c;
    ERR_GOST_error(0x7a,0x84,"gost94_keyx.c",0xfb);
  }
  else {
    iVar3 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (iVar3 < 1) {
      ERR_GOST_error(0x7a,0x83,"gost94_keyx.c",0xf1);
    }
    else {
LAB_00119a3c:
      pEVar4 = EVP_PKEY_CTX_get0_peerkey(param_1);
      if (pEVar4 == (EVP_PKEY *)0x0) {
        ERR_GOST_error(0x7a,0x78,"gost94_keyx.c",0x103);
      }
      else {
        iVar3 = get_encryption_params(*(undefined4 *)piVar2[1]);
        if (iVar3 != 0) {
          gost_init(auStack_1098,*(undefined4 *)(iVar3 + 4));
          piVar6 = *(int **)(piVar2[1] + 8);
          if (*piVar6 != 8) {
            OpenSSLDie("gost94_keyx.c",0x10d,"gkt->key_agreement_info->eph_iv->length==8");
            piVar6 = *(int **)(piVar2[1] + 8);
          }
          local_58 = *(undefined4 *)piVar6[2];
          uStack_54 = ((undefined4 *)piVar6[2])[1];
          piVar6 = *(int **)*piVar2;
          if (*piVar6 != 0x20) {
            OpenSSLDie("gost94_keyx.c",0x10f,"gkt->key_info->encrypted_key->length==32");
            piVar6 = *(int **)*piVar2;
          }
          puVar7 = (undefined4 *)piVar6[2];
          local_50 = *puVar7;
          uStack_4c = puVar7[1];
          uStack_48 = puVar7[2];
          uStack_44 = puVar7[3];
          uStack_38 = puVar7[6];
          uStack_34 = puVar7[7];
          local_40 = puVar7[4];
          uStack_3c = puVar7[5];
          piVar6 = *(int **)(*piVar2 + 4);
          if (*piVar6 != 4) {
            OpenSSLDie("gost94_keyx.c",0x111,"gkt->key_info->imit->length==4");
            piVar6 = *(int **)(*piVar2 + 4);
          }
          local_30 = *(undefined4 *)piVar6[2];
          uVar5 = gost_get0_priv_key(pEVar1);
          make_cp_exchange_key(uVar5,pEVar4,auStack_78);
          iVar3 = keyUnwrapCryptoPro(auStack_1098,auStack_78,&local_58,param_2);
          if (iVar3 != 0) {
            EVP_PKEY_free(peer);
            GOST_KEY_TRANSPORT_free(piVar2);
            piVar2 = (int *)0x1;
            goto LAB_00119b40;
          }
          ERR_GOST_error(0x7a,0x66,"gost94_keyx.c",0x117);
        }
      }
    }
  }
  EVP_PKEY_free(peer);
  GOST_KEY_TRANSPORT_free(piVar2);
  piVar2 = (int *)0xffffffff;
LAB_00119b40:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(piVar2);
}

