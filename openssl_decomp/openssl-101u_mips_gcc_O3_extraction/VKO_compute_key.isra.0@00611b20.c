
undefined4
VKO_compute_key_isra_0(int param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  undefined uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined *puVar13;
  int iVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  undefined auStack_128 [116];
  undefined local_b4;
  undefined local_b3;
  undefined local_b2;
  undefined local_b1;
  undefined local_b0;
  undefined local_af;
  undefined local_ae;
  undefined local_ad;
  undefined local_ac [32];
  undefined auStack_8c [31];
  undefined uStack_6d;
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(param_3);
  uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_3);
  uVar4 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar4);
  uVar5 = (*(code *)PTR_BN_CTX_new_006a794c)();
  local_ad = *param_4;
  local_ae = param_4[1];
  local_af = param_4[2];
  local_b0 = param_4[3];
  local_b1 = param_4[4];
  local_b2 = param_4[5];
  local_b3 = param_4[6];
  local_b4 = param_4[7];
  (*(code *)PTR_BN_CTX_start_006a8528)(uVar5);
  uVar6 = (*(code *)PTR_getbnfrombuf_006a9810)(&local_b4,8);
  uVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(uVar5);
  uVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(uVar5);
  uVar9 = (*(code *)PTR_BN_CTX_get_006a852c)(uVar5);
  uVar10 = (*(code *)PTR_BN_CTX_get_006a852c)(uVar5);
  uVar11 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_3);
  (*(code *)PTR_EC_GROUP_get_order_006a71ec)(uVar11,uVar8,uVar5);
  (*(code *)PTR_BN_mod_mul_006a8574)(uVar7,uVar3,uVar6,uVar8,uVar5);
  uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_3);
  puVar15 = local_ac;
  (*(code *)PTR_EC_POINT_mul_006a8648)(uVar3,uVar4,0,param_2,uVar7,uVar5);
  uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_3);
  (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)(uVar3,uVar4,uVar9,uVar10,uVar5);
  (*(code *)PTR_store_bignum_006a9814)(uVar10,puVar15,0x20);
  (*(code *)PTR_store_bignum_006a9814)(uVar9,auStack_8c,0x20);
  puVar12 = auStack_6c + 0x3f;
  do {
    uVar1 = *puVar15;
    puVar13 = puVar12 + -1;
    puVar15 = puVar15 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar13;
  } while (&uStack_6d != puVar13);
  init_gost_hash_ctx(auStack_128,PTR_GostR3411_94_CryptoProParamSet_006a95cc);
  start_hash(auStack_128);
  puVar16 = (undefined4 *)&DAT_00000040;
  hash_block(auStack_128,auStack_6c);
  finish_hash(auStack_128);
  done_gost_hash_ctx(auStack_128);
  (*(code *)PTR_BN_free_006a701c)(uVar6);
  (*(code *)PTR_BN_CTX_end_006a8530)(uVar5);
  (*(code *)PTR_BN_CTX_free_006a7954)(uVar5);
  (*(code *)PTR_EC_POINT_free_006a7fac)(uVar4);
  if (local_2c == *(int *)puVar2) {
    return 0x20;
  }
  iVar14 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar3 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  uVar4 = (*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006a9824)(iVar14);
  iVar14 = (*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)(iVar14);
  if (*(int *)(iVar14 + 8) == 0) {
    ERR_GOST_error(0x79,0x80,"gost2001_keyx.c",0x55);
    uVar3 = 0;
  }
  else {
    if (param_1 == 0) {
      *puVar16 = 0x20;
      return 0x20;
    }
    uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar4);
    uVar4 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(uVar4);
    uVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar3);
    uVar4 = VKO_compute_key_isra_0(param_1,uVar4,uVar3,*(undefined4 *)(iVar14 + 8));
    uVar3 = 1;
    *puVar16 = uVar4;
  }
  return uVar3;
}

