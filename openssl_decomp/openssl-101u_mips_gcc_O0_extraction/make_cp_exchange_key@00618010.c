
undefined4 make_cp_exchange_key(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined *unaff_s0;
  undefined4 *unaff_s1;
  undefined4 unaff_s2;
  undefined *unaff_s3;
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  undefined4 unaff_s6;
  code *pcVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  undefined4 unaff_retaddr;
  undefined auStackX_0 [16];
  
  while( true ) {
    puVar9 = param_3;
    uVar8 = param_1;
    puVar2 = PTR___stack_chk_guard_006a9ae8;
    *(undefined4 *)((int)register0x00000074 + -0x18) = unaff_s2;
    *(undefined4 *)((int)register0x00000074 + -8) = unaff_s6;
    *(undefined4 **)((int)register0x00000074 + -0xc) = unaff_s5;
    *(undefined4 **)((int)register0x00000074 + -0x10) = unaff_s4;
    *(undefined **)((int)register0x00000074 + -0x1a0) = &_gp;
    *(undefined4 *)((int)register0x00000074 + -4) = unaff_retaddr;
    *(undefined **)((int)register0x00000074 + -0x14) = unaff_s3;
    *(undefined4 **)((int)register0x00000074 + -0x1c) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x20) = unaff_s0;
    *(undefined4 *)((int)register0x00000074 + -0x24) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8
    ;
    param_3 = param_2;
    puVar10 = puVar9;
    puVar3 = (undefined4 *)(*(code *)PTR_DH_new_006a751c)();
    puVar12 = *(undefined **)((int)register0x00000074 + -0x1a0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar4 = 0;
      unaff_s5 = param_2;
    }
    else {
      unaff_s3 = (undefined *)((int)register0x00000074 + -0x124);
      (**(code **)(puVar12 + -0x53ec))(unaff_s3,0,0x80);
      unaff_s0 = (undefined *)((int)register0x00000074 + -0xa4);
      uVar4 = (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6bc8))
                        (*(undefined4 *)(param_2[5] + 0x14));
      iVar13 = *(int *)((int)register0x00000074 + -0x1a0);
      puVar3[3] = uVar4;
      uVar4 = (**(code **)(iVar13 + -0x6bc8))(*(undefined4 *)(param_2[5] + 0xc));
      pcVar11 = *(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6bc8);
      puVar3[2] = uVar4;
      uVar4 = (*pcVar11)(uVar8);
      pcVar11 = *(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x5808);
      puVar3[6] = uVar4;
      iVar5 = (*pcVar11)(param_2);
      param_3 = *(undefined4 **)(iVar5 + 0x18);
      puVar10 = puVar3;
      unaff_s5 = (undefined4 *)
                 (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6e3c))(unaff_s0);
      unaff_s1 = puVar3;
      if (unaff_s5 == (undefined4 *)0x0) {
        (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x78d8))(puVar3);
        uVar4 = 0;
        puVar12 = *(undefined **)((int)register0x00000074 + -0x1a0);
      }
      else {
        (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x53ec))(unaff_s3,0,0x80);
        iVar14 = *(int *)((int)register0x00000074 + -0x1a0);
        if (0 < (int)unaff_s5) {
          puVar6 = unaff_s0 + (int)((int)unaff_s5 + -1);
          puVar7 = unaff_s3;
          do {
            uVar1 = *puVar6;
            puVar6 = puVar6 + -1;
            *puVar7 = uVar1;
            puVar7 = puVar7 + 1;
          } while (puVar6 != (undefined *)((int)register0x00000074 + -0xa5));
        }
        unaff_s0 = (undefined *)((int)register0x00000074 + -0x198);
        (**(code **)(iVar14 + -0x78d8))(puVar3);
        init_gost_hash_ctx(unaff_s0,*(undefined4 *)
                                     (*(int *)((int)register0x00000074 + -0x1a0) + -0x5814));
        start_hash(unaff_s0);
        puVar10 = (undefined4 *)&DAT_00000080;
        hash_block(unaff_s0,unaff_s3);
        param_3 = puVar9;
        finish_hash(unaff_s0);
        done_gost_hash_ctx(unaff_s0);
        uVar4 = 1;
        puVar12 = *(undefined **)((int)register0x00000074 + -0x1a0);
      }
    }
    iVar5 = *(int *)((int)register0x00000074 + -0x24);
    if (iVar5 == *(int *)puVar2) break;
    pcVar11 = pkey_gost94_derive;
    (**(code **)(puVar12 + -0x5330))();
    *(code **)((int)register0x00000074 + -0x1b4) = pcVar11;
    *(undefined **)((int)register0x00000074 + -0x1b8) = puVar2;
    *(undefined4 **)((int)register0x00000074 + -0x1bc) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x1c0) = unaff_s0;
    *(undefined **)((int)register0x00000074 + -0x1c8) = &_gp;
    param_2 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006a9824)();
    uVar4 = (**(code **)(*(int *)((int)register0x00000074 + -0x1c8) + -0x580c))(iVar5);
    *puVar10 = 0x20;
    if (param_3 == (undefined4 *)0x0) {
      return 1;
    }
    param_1 = gost_get0_priv_key(uVar4);
    unaff_retaddr = *(undefined4 *)((int)register0x00000074 + -0x1b4);
    unaff_s2 = *(undefined4 *)((int)register0x00000074 + -0x1b8);
    unaff_s1 = *(undefined4 **)((int)register0x00000074 + -0x1bc);
    unaff_s0 = *(undefined **)((int)register0x00000074 + -0x1c0);
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x1b0);
    unaff_s4 = puVar9;
    unaff_s6 = uVar8;
  }
  return uVar4;
}

