
void pkey_GOST01cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  EVP_PKEY *pkey;
  void *pvVar1;
  int *piVar2;
  EVP_PKEY *pkey_00;
  int *piVar3;
  int iVar4;
  EC_KEY *pEVar5;
  EC_POINT *pEVar6;
  ASN1_OBJECT *pAVar7;
  int *piVar8;
  ASN1_OBJECT **ppAVar9;
  bool bVar10;
  undefined4 *puVar11;
  int local_10a4;
  undefined auStack_10a0 [4128];
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined auStack_78 [32];
  undefined auStack_58 [8];
  undefined auStack_50 [32];
  undefined auStack_30 [4];
  int local_2c;
  
  piVar8 = &local_10a4;
  local_2c = __TMC_END__;
  local_10a4 = param_2;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar1 = EVP_PKEY_CTX_get_data(param_1);
  piVar2 = (int *)get_encryption_params(0);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  puVar11 = *(undefined4 **)((int)pvVar1 + 8);
  if (puVar11 == (undefined4 *)0x0) {
    if ((local_10a4 != 0) && (iVar4 = RAND_bytes((uchar *)&local_80,8), iVar4 < 1)) {
      ERR_GOST_error(0x77,0x7c,"gost2001_keyx.c",0x8a);
      goto LAB_001131d6;
    }
  }
  else {
    local_80 = *puVar11;
    uStack_7c = puVar11[1];
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    if (local_10a4 == 0) {
LAB_00113226:
      bVar10 = true;
      iVar4 = get_gost_engine_param(0);
      goto joined_r0x00113232;
    }
    pkey_00 = EVP_PKEY_new();
    iVar4 = EVP_PKEY_base_id(pkey);
    pEVar5 = EC_KEY_new();
    EVP_PKEY_assign(pkey_00,iVar4,pEVar5);
    EVP_PKEY_copy_parameters(pkey_00,pkey);
    EVP_PKEY_get0(pkey_00);
    piVar3 = (int *)gost2001_keygen();
    if (piVar3 != (int *)0x0) goto LAB_00113226;
    bVar10 = true;
LAB_0011324e:
    if (pkey_00 == (EVP_PKEY *)0x0) {
      bVar10 = false;
    }
    if (bVar10) {
      EVP_PKEY_free(pkey_00);
    }
  }
  else {
    bVar10 = false;
    piVar3 = (int *)gost_get0_priv_key(pkey_00);
    if (piVar3 != (int *)0x0) {
      iVar4 = get_gost_engine_param(0);
joined_r0x00113232:
      if ((iVar4 == 0) && (piVar2 == &gost_cipher_list)) {
        piVar2 = &DAT_00195a9c;
      }
      if (local_10a4 != 0) {
        pEVar5 = (EC_KEY *)EVP_PKEY_get0(pkey);
        pEVar6 = EC_KEY_get0_public_key(pEVar5);
        pvVar1 = EVP_PKEY_get0(pkey_00);
        VKO_compute_key_isra_0(auStack_78,pEVar6,pvVar1,&local_80);
        gost_init(auStack_10a0,piVar2[1]);
        keyWrapCryptoPro(auStack_10a0,auStack_78,&local_80,param_4,auStack_58);
      }
      piVar3 = (int *)GOST_KEY_TRANSPORT_new();
      if ((((piVar3 != (int *)0x0) &&
           (iVar4 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar3[1] + 8),&local_80,8), iVar4 != 0)
           ) && (iVar4 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar3 + 4),auStack_30,4),
                iVar4 != 0)) &&
         (iVar4 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar3,auStack_50,0x20), iVar4 != 0)) {
        if (bVar10) {
          if (local_10a4 != 0) {
            pkey = pkey_00;
          }
          iVar4 = X509_PUBKEY_set((X509_PUBKEY **)(piVar3[1] + 4),pkey);
          if (iVar4 == 0) {
            bVar10 = true;
            ERR_GOST_error(0x77,0x65,"gost2001_keyx.c");
            goto LAB_0011324e;
          }
          ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar3[1]);
          ppAVar9 = (ASN1_OBJECT **)piVar3[1];
          pAVar7 = OBJ_nid2obj(*piVar2);
          *ppAVar9 = pAVar7;
          if (pkey_00 != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(pkey_00);
          }
        }
        else {
          ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar3[1]);
          ppAVar9 = (ASN1_OBJECT **)piVar3[1];
          pAVar7 = OBJ_nid2obj(*piVar2);
          *ppAVar9 = pAVar7;
          iVar4 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
          if (iVar4 < 1) {
            ERR_GOST_error(0x77,0x84,"gost2001_keyx.c",0xd4);
            goto LAB_0011325a;
          }
        }
        if (local_10a4 == 0) {
          piVar8 = (int *)0x0;
        }
        puVar11 = (undefined4 *)i2d_GOST_KEY_TRANSPORT(piVar3,piVar8);
        *param_3 = puVar11;
        if (puVar11 != (undefined4 *)0x0) {
          puVar11 = (undefined4 *)0x1;
        }
        GOST_KEY_TRANSPORT_free(piVar3);
        goto LAB_001131d6;
      }
      goto LAB_0011324e;
    }
    ERR_GOST_error(0x77,0x79,"gost2001_keyx.c",0x95);
  }
LAB_0011325a:
  puVar11 = (undefined4 *)0xffffffff;
  GOST_KEY_TRANSPORT_free(piVar3);
LAB_001131d6:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(puVar11);
  }
  return;
}

