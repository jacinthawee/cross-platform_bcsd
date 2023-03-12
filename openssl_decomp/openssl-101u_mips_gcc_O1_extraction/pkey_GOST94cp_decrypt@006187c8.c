
undefined4
pkey_GOST94cp_decrypt
          (undefined4 param_1,int param_2,undefined4 *param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  int **ppiVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  uint uVar17;
  char *pcVar18;
  uint uVar19;
  char *pcVar20;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint local_109c;
  undefined auStack_1098 [4128];
  undefined auStack_78 [32];
  char *local_58;
  char *local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_109c = param_4;
  uVar11 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  if (param_2 == 0) {
    uVar11 = 1;
    *param_3 = 0x20;
    goto LAB_00618a7c;
  }
  ppiVar12 = (int **)d2i_GOST_KEY_TRANSPORT(0,&local_109c,param_5);
  if (ppiVar12 == (int **)0x0) {
    ERR_GOST_error(0x7a,0x68,"gost94_keyx.c",0xe6);
    uVar11 = 0;
    goto LAB_00618a7c;
  }
  iVar13 = (*(code *)PTR_X509_PUBKEY_get_006a8d64)(ppiVar12[1][1]);
  if (iVar13 == 0) {
    param_4 = 2;
    iVar14 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(param_1,0xffffffff,0xffffffff,2,3,0);
    if (0 < iVar14) goto LAB_00618884;
    ERR_GOST_error(0x7a,0x84,"gost94_keyx.c",0xf4);
  }
  else {
    iVar14 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a7cf0)(param_1,iVar13);
    if (iVar14 < 1) {
      ERR_GOST_error(0x7a,0x83,"gost94_keyx.c",0xed);
    }
    else {
LAB_00618884:
      iVar14 = (*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006a9824)(param_1);
      if (iVar14 == 0) {
        ERR_GOST_error(0x7a,0x78,"gost94_keyx.c",0xfa);
      }
      else {
        iVar15 = get_encryption_params(*ppiVar12[1]);
        if (iVar15 != 0) {
          gost_init(auStack_1098,*(undefined4 *)(iVar15 + 4));
          piVar16 = (int *)ppiVar12[1][2];
          if (*piVar16 != 8) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("gost94_keyx.c",0x104,"gkt->key_agreement_info->eph_iv->length == 8");
            piVar16 = (int *)ppiVar12[1][2];
          }
          uVar19 = 0x20;
          local_58 = *(char **)piVar16[2];
          local_54 = ((char **)piVar16[2])[1];
          piVar16 = (int *)**ppiVar12;
          pcVar20 = (char *)0x680000;
          pcVar18 = local_58;
          if (*piVar16 != 0x20) {
            pcVar20 = "gkt->key_info->encrypted_key->length == 32";
            uVar19 = 0x106;
            pcVar18 = "gost94_keyx.c";
            (*(code *)PTR_OpenSSLDie_006a7c5c)();
            piVar16 = (int *)**ppiVar12;
          }
          uVar17 = piVar16[2];
          uVar1 = uVar17 & 3;
          uVar2 = uVar17 + 4 & 3;
          uVar3 = uVar17 + 8 & 3;
          uVar4 = uVar17 + 0xc & 3;
          uVar5 = uVar17 + 0x10 & 3;
          uVar6 = uVar17 + 0x14 & 3;
          uVar7 = uVar17 + 0x18 & 3;
          uVar8 = uVar17 + 0x1c & 3;
          uVar9 = uVar17 + 3 & 3;
          local_50 = (*(int *)(uVar17 - uVar1) << uVar1 * 8 | in_t3 & 0xffffffffU >> (4 - uVar1) * 8
                     ) & -1 << (uVar9 + 1) * 8 | *(uint *)((uVar17 + 3) - uVar9) >> (3 - uVar9) * 8;
          uVar1 = uVar17 + 7 & 3;
          local_4c = (*(int *)((uVar17 + 4) - uVar2) << uVar2 * 8 |
                     in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 7) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar17 + 0xb & 3;
          local_48 = (*(int *)((uVar17 + 8) - uVar3) << uVar3 * 8 |
                     in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 0xb) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar17 + 0xf & 3;
          local_44 = (*(int *)((uVar17 + 0xc) - uVar4) << uVar4 * 8 |
                     in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 0xf) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar17 + 0x13 & 3;
          local_40 = (*(int *)((uVar17 + 0x10) - uVar5) << uVar5 * 8 |
                     param_4 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 0x13) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar17 + 0x17 & 3;
          local_3c = (*(int *)((uVar17 + 0x14) - uVar6) << uVar6 * 8 |
                     (uint)pcVar20 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 0x17) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar17 + 0x1b & 3;
          local_38 = (*(int *)((uVar17 + 0x18) - uVar7) << uVar7 * 8 |
                     uVar19 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar17 + 0x1b) - uVar1) >> (3 - uVar1) * 8;
          uVar19 = uVar17 + 0x1f & 3;
          local_34 = (*(int *)((uVar17 + 0x1c) - uVar8) << uVar8 * 8 |
                     (uint)pcVar18 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar19 + 1) * 8 |
                     *(uint *)((uVar17 + 0x1f) - uVar19) >> (3 - uVar19) * 8;
          piVar16 = (int *)(*ppiVar12)[1];
          if (*piVar16 != 4) {
            (*(code *)PTR_OpenSSLDie_006a7c5c)
                      ("gost94_keyx.c",0x108,"gkt->key_info->imit->length == 4");
            piVar16 = (int *)(*ppiVar12)[1];
          }
          local_30 = *(undefined4 *)piVar16[2];
          uVar11 = gost_get0_priv_key(uVar11);
          make_cp_exchange_key(uVar11,iVar14,auStack_78);
          iVar14 = keyUnwrapCryptoPro(auStack_1098,auStack_78,&local_58,param_2);
          if (iVar14 != 0) {
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar13);
            GOST_KEY_TRANSPORT_free(ppiVar12);
            uVar11 = 1;
            goto LAB_00618a7c;
          }
          ERR_GOST_error(0x7a,0x66,"gost94_keyx.c",0x10d);
        }
      }
    }
  }
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar13);
  GOST_KEY_TRANSPORT_free(ppiVar12);
  uVar11 = 0xffffffff;
LAB_00618a7c:
  if (local_2c == *(int *)puVar10) {
    return uVar11;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return 0x40;
}

