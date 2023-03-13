
uint pkey_GOST01cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  ASN1_OBJECT **ppAVar2;
  bool bVar3;
  EVP_PKEY *pkey;
  void *pvVar4;
  int *piVar5;
  EVP_PKEY *pkey_00;
  int iVar6;
  EC_KEY *pEVar7;
  int *piVar8;
  ASN1_OBJECT *pAVar9;
  uint uVar10;
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
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar4 = EVP_PKEY_CTX_get_data(param_1);
  piVar5 = (int *)get_encryption_params(0);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  puVar1 = *(undefined4 **)((int)pvVar4 + 8);
  if (puVar1 == (undefined4 *)0x0) {
    if (local_10a0[0] != 0) {
      iVar6 = RAND_bytes((uchar *)&local_74,8);
      if (iVar6 < 1) {
        uVar10 = 0;
        ERR_GOST_error(0x77,0x7c,"gost2001_keyx.c",0x86);
        goto LAB_081d2d48;
      }
      goto LAB_081d2b8e;
    }
    if (pkey_00 == (EVP_PKEY *)0x0) goto LAB_081d2ed0;
LAB_081d2b96:
    iVar6 = gost_get0_priv_key(pkey_00);
    if (iVar6 != 0) {
      bVar3 = false;
LAB_081d2bb2:
      iVar6 = get_gost_engine_param(0);
      if ((iVar6 == 0) && (piVar5 == (int *)gost_cipher_list)) {
        piVar5 = (int *)(gost_cipher_list + 0xc);
      }
      if (local_10a0[0] != 0) {
        EVP_PKEY_get0(pkey_00);
        pEVar7 = (EC_KEY *)EVP_PKEY_get0(pkey);
        EC_KEY_get0_public_key(pEVar7);
        VKO_compute_key_isra_0(&local_74);
        gost_init(local_1094,piVar5[1]);
        keyWrapCryptoPro(local_1094,local_6c,&local_74,param_4,local_4c);
      }
      piVar8 = (int *)GOST_KEY_TRANSPORT_new();
      if ((((piVar8 != (int *)0x0) &&
           (iVar6 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar8[1] + 8),&local_74,8), iVar6 != 0)
           ) && (iVar6 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar8 + 4),local_24,4),
                iVar6 != 0)) &&
         (iVar6 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar8,local_44,0x20), iVar6 != 0)) {
        if (bVar3) {
          if (local_10a0[0] != 0) {
            pkey = pkey_00;
          }
          iVar6 = X509_PUBKEY_set((X509_PUBKEY **)(piVar8[1] + 4),pkey);
          if (iVar6 == 0) {
            ERR_GOST_error(0x77,0x65,"gost2001_keyx.c",0xba);
            bVar3 = true;
            goto LAB_081d2e68;
          }
          ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar8[1]);
          ppAVar2 = (ASN1_OBJECT **)piVar8[1];
          pAVar9 = OBJ_nid2obj(*piVar5);
          *ppAVar2 = pAVar9;
          if (pkey_00 != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(pkey_00);
          }
        }
        else {
          ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar8[1]);
          ppAVar2 = (ASN1_OBJECT **)piVar8[1];
          pAVar9 = OBJ_nid2obj(*piVar5);
          *ppAVar2 = pAVar9;
          iVar6 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
          if (iVar6 < 1) {
            ERR_GOST_error(0x77,0x84,"gost2001_keyx.c",0xc6);
            goto LAB_081d2e40;
          }
        }
        piVar5 = local_10a0;
        if (local_10a0[0] == 0) {
          piVar5 = (int *)0x0;
        }
        iVar6 = i2d_GOST_KEY_TRANSPORT(piVar8,piVar5);
        uVar10 = (uint)(iVar6 != 0);
        *param_3 = iVar6;
        GOST_KEY_TRANSPORT_free(piVar8);
        goto LAB_081d2d48;
      }
      goto LAB_081d2e68;
    }
    piVar8 = (int *)0x0;
    ERR_GOST_error(0x77,0x79,"gost2001_keyx.c",0x8f);
  }
  else {
    local_70 = puVar1[1];
    local_74 = *puVar1;
LAB_081d2b8e:
    if (pkey_00 != (EVP_PKEY *)0x0) goto LAB_081d2b96;
    if (local_10a0[0] == 0) {
LAB_081d2ed0:
      pkey_00 = (EVP_PKEY *)0x0;
      bVar3 = true;
      goto LAB_081d2bb2;
    }
    pkey_00 = EVP_PKEY_new();
    pEVar7 = EC_KEY_new();
    iVar6 = EVP_PKEY_base_id(pkey);
    EVP_PKEY_assign(pkey_00,iVar6,pEVar7);
    EVP_PKEY_copy_parameters(pkey_00,pkey);
    pvVar4 = EVP_PKEY_get0(pkey_00);
    iVar6 = gost2001_keygen(pvVar4);
    if (iVar6 != 0) {
      bVar3 = true;
      goto LAB_081d2bb2;
    }
    bVar3 = true;
    piVar8 = (int *)0x0;
LAB_081d2e68:
    if ((pkey_00 != (EVP_PKEY *)0x0) && (bVar3)) {
      EVP_PKEY_free(pkey_00);
    }
  }
LAB_081d2e40:
  uVar10 = 0xffffffff;
  GOST_KEY_TRANSPORT_free(piVar8);
LAB_081d2d48:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

