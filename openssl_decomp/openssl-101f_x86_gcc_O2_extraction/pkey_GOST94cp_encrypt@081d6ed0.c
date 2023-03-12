
undefined4 pkey_GOST94cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,int *param_3,undefined4 param_4)

{
  ASN1_OBJECT **ppAVar1;
  bool bVar2;
  int *piVar3;
  EVP_PKEY *pkey;
  void *pvVar4;
  EVP_PKEY *pkey_00;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  ASN1_OBJECT *pAVar8;
  undefined4 uVar9;
  DSA *key;
  void *pvVar10;
  int iVar11;
  int in_GS_OFFSET;
  int local_10a0 [3];
  undefined local_1094 [4128];
  undefined4 local_74;
  undefined4 local_70;
  undefined local_6c [32];
  undefined local_4c [8];
  undefined local_44 [32];
  undefined local_24 [4];
  int local_20;
  
  local_10a0[0] = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar3 = (int *)get_encryption_params(0);
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar4 = EVP_PKEY_CTX_get_data(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  iVar5 = get_gost_engine_param(0);
  if ((iVar5 == 0) && (piVar3 == (int *)gost_cipher_list)) {
    piVar3 = (int *)(gost_cipher_list + 0xc);
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    if (local_10a0[0] == 0) {
      bVar2 = true;
    }
    else {
      pkey_00 = EVP_PKEY_new();
      key = DSA_new();
      iVar5 = EVP_PKEY_base_id(pkey);
      EVP_PKEY_assign(pkey_00,iVar5,key);
      EVP_PKEY_copy_parameters(pkey_00,pkey);
      pvVar10 = EVP_PKEY_get0(pkey_00);
      iVar5 = gost_sign_keygen(pvVar10);
      if (iVar5 == 0) {
        piVar7 = (int *)0x0;
        goto LAB_081d720e;
      }
      bVar2 = true;
      if (local_10a0[0] != 0) goto LAB_081d6f8b;
    }
LAB_081d71d8:
    puVar6 = *(undefined4 **)((int)pvVar4 + 8);
    iVar5 = 0;
    if (puVar6 != (undefined4 *)0x0) {
LAB_081d6fb6:
      local_70 = puVar6[1];
      local_74 = *puVar6;
LAB_081d6fc9:
      if (iVar5 != 0) {
        gost_init(local_1094,piVar3[1]);
        keyWrapCryptoPro(local_1094,local_6c,&local_74,param_4,local_4c);
      }
    }
LAB_081d7003:
    piVar7 = (int *)GOST_KEY_TRANSPORT_new();
    if ((((piVar7 == (int *)0x0) ||
         (iVar5 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar7[1] + 8),&local_74,8), iVar5 == 0))
        || (iVar5 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar7 + 4),local_24,4), iVar5 == 0))
       || (iVar5 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar7,local_44,0x20), iVar5 == 0)) {
      if (bVar2) {
        EVP_PKEY_free(pkey_00);
      }
      ERR_GOST_error(0x7b,0x75,"gost94_keyx.c",0xca);
    }
    else {
      if (bVar2) {
        if (local_10a0[0] != 0) {
          pkey = pkey_00;
        }
        iVar5 = X509_PUBKEY_set((X509_PUBKEY **)(piVar7[1] + 4),pkey);
        if (iVar5 == 0) {
          ERR_GOST_error(0x7b,0x65,"gost94_keyx.c",0xac);
          goto LAB_081d720e;
        }
        if (local_10a0[0] != 0) {
          EVP_PKEY_free(pkey_00);
        }
      }
      ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar7[1]);
      ppAVar1 = (ASN1_OBJECT **)piVar7[1];
      pAVar8 = OBJ_nid2obj(*piVar3);
      *ppAVar1 = pAVar8;
      piVar3 = local_10a0;
      if (local_10a0[0] == 0) {
        piVar3 = (int *)0x0;
      }
      iVar5 = i2d_GOST_KEY_TRANSPORT(piVar7,piVar3);
      *param_3 = iVar5;
      if (iVar5 == 0) {
        ERR_GOST_error(0x7b,0x67,"gost94_keyx.c",0xb6);
      }
      else {
        if ((bVar2) || (iVar5 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0), 0 < iVar5)) {
          GOST_KEY_TRANSPORT_free(piVar7);
          uVar9 = 1;
          goto LAB_081d713e;
        }
        ERR_GOST_error(0x7b,0x84,"gost94_keyx.c",0xbf);
      }
    }
  }
  else {
    iVar5 = gost_get0_priv_key(pkey_00);
    if (iVar5 != 0) {
      bVar2 = false;
      if (local_10a0[0] == 0) goto LAB_081d71d8;
LAB_081d6f8b:
      gost_get0_priv_key(pkey_00);
      make_cp_exchange_key();
      puVar6 = *(undefined4 **)((int)pvVar4 + 8);
      iVar5 = local_10a0[0];
      if (puVar6 != (undefined4 *)0x0) goto LAB_081d6fb6;
      if (local_10a0[0] == 0) goto LAB_081d7003;
      iVar11 = RAND_bytes((uchar *)&local_74,8);
      iVar5 = local_10a0[0];
      if (iVar11 < 1) {
        piVar7 = (int *)0x0;
        ERR_GOST_error(0x7b,0x7c,"gost94_keyx.c",0x8e);
        goto LAB_081d720e;
      }
      goto LAB_081d6fc9;
    }
    piVar7 = (int *)0x0;
    ERR_GOST_error(0x7b,0x79,"gost94_keyx.c",0x70);
  }
LAB_081d720e:
  GOST_KEY_TRANSPORT_free(piVar7);
  uVar9 = 0xffffffff;
LAB_081d713e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}

