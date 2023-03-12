
void pkey_GOST94cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  EVP_PKEY *pkey;
  void *pvVar2;
  EVP_PKEY *pkey_00;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  ASN1_OBJECT *pAVar6;
  DSA *key;
  int iVar7;
  int *piVar8;
  ASN1_OBJECT **ppAVar9;
  bool bVar10;
  int local_10a4;
  undefined auStack_10a0 [4128];
  int local_80;
  int iStack_7c;
  undefined auStack_78 [32];
  undefined auStack_58 [8];
  undefined auStack_50 [32];
  undefined auStack_30 [4];
  int local_2c;
  
  piVar8 = &local_10a4;
  local_2c = __TMC_END__;
  local_10a4 = param_2;
  piVar1 = (int *)get_encryption_params(0);
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar2 = EVP_PKEY_CTX_get_data(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  iVar3 = get_gost_engine_param(0);
  if ((iVar3 == 0) && (piVar1 == &gost_cipher_list)) {
    piVar1 = &DAT_00195a9c;
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    if (local_10a4 == 0) {
      bVar10 = true;
LAB_00119968:
      piVar4 = *(int **)((int)pvVar2 + 8);
      if (piVar4 != (int *)0x0) {
        iVar3 = 0;
LAB_0011979a:
        local_80 = *piVar4;
        iStack_7c = piVar4[1];
        goto LAB_001197ac;
      }
      goto LAB_001197d4;
    }
    pkey_00 = EVP_PKEY_new();
    iVar3 = EVP_PKEY_base_id(pkey);
    key = DSA_new();
    EVP_PKEY_assign(pkey_00,iVar3,key);
    EVP_PKEY_copy_parameters(pkey_00,pkey);
    EVP_PKEY_get0(pkey_00);
    piVar4 = (int *)gost_sign_keygen();
    if (piVar4 != (int *)0x0) {
      bVar10 = true;
      goto LAB_00119772;
    }
  }
  else {
    piVar4 = (int *)gost_get0_priv_key(pkey_00);
    if (piVar4 == (int *)0x0) {
      ERR_GOST_error(0x7b,0x79,"gost94_keyx.c",0x70);
    }
    else {
      bVar10 = false;
LAB_00119772:
      if (local_10a4 == 0) goto LAB_00119968;
      uVar5 = gost_get0_priv_key(pkey_00);
      make_cp_exchange_key(uVar5,pkey,auStack_78);
      piVar4 = *(int **)((int)pvVar2 + 8);
      iVar3 = local_10a4;
      if (piVar4 != (int *)0x0) goto LAB_0011979a;
      if (local_10a4 == 0) goto LAB_001197d4;
      iVar7 = RAND_bytes((uchar *)&local_80,8);
      iVar3 = local_10a4;
      if (iVar7 < 1) {
        ERR_GOST_error(0x7b,0x7c,"gost94_keyx.c",0x8e);
        goto LAB_00119906;
      }
LAB_001197ac:
      if (iVar3 != 0) {
        gost_init(auStack_10a0,piVar1[1]);
        keyWrapCryptoPro(auStack_10a0,auStack_78,&local_80,param_4,auStack_58);
      }
LAB_001197d4:
      piVar4 = (int *)GOST_KEY_TRANSPORT_new();
      if ((((piVar4 == (int *)0x0) ||
           (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar4[1] + 8),&local_80,8), iVar3 == 0)
           ) || (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar4 + 4),auStack_30,4),
                iVar3 == 0)) ||
         (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar4,auStack_50,0x20), iVar3 == 0)) {
        if (bVar10) {
          EVP_PKEY_free(pkey_00);
        }
        ERR_GOST_error(0x7b,0x75,"gost94_keyx.c",0xca);
      }
      else {
        if (bVar10) {
          if (local_10a4 != 0) {
            pkey = pkey_00;
          }
          iVar3 = X509_PUBKEY_set((X509_PUBKEY **)(piVar4[1] + 4),pkey);
          if (iVar3 == 0) {
            ERR_GOST_error(0x7b,0x65,"gost94_keyx.c",0xac);
            goto LAB_00119906;
          }
          if (local_10a4 != 0) {
            EVP_PKEY_free(pkey_00);
          }
        }
        ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar4[1]);
        ppAVar9 = (ASN1_OBJECT **)piVar4[1];
        pAVar6 = OBJ_nid2obj(*piVar1);
        if (local_10a4 == 0) {
          piVar8 = (int *)0x0;
        }
        *ppAVar9 = pAVar6;
        iVar3 = i2d_GOST_KEY_TRANSPORT(piVar4,piVar8);
        *param_3 = iVar3;
        if (iVar3 == 0) {
          ERR_GOST_error(0x7b,0x67,"gost94_keyx.c",0xb6);
        }
        else {
          if ((bVar10) || (iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0), 0 < iVar3)) {
            GOST_KEY_TRANSPORT_free(piVar4);
            uVar5 = 1;
            goto LAB_0011989c;
          }
          ERR_GOST_error(0x7b,0x84,"gost94_keyx.c",0xbf);
        }
      }
    }
  }
LAB_00119906:
  GOST_KEY_TRANSPORT_free(piVar4);
  uVar5 = 0xffffffff;
LAB_0011989c:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}

