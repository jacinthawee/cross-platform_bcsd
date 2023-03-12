
undefined4 pkey_gost94_derive(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined *unaff_s0;
  undefined4 *unaff_s1;
  undefined *unaff_s2;
  undefined *unaff_s3;
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  undefined4 unaff_s6;
  code *pcVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  while( true ) {
    puVar9 = param_2;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(undefined **)((int)register0x00000074 + -8) = unaff_s2;
    *(undefined4 **)((int)register0x00000074 + -0xc) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x10) = unaff_s0;
    *(undefined **)((int)register0x00000074 + -0x18) = &_gp;
    puVar6 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006aa934)();
    uVar7 = (**(code **)(*(int *)((int)register0x00000074 + -0x18) + -0x5800))(param_1);
    *param_3 = 0x20;
    if (puVar9 == (undefined4 *)0x0) {
      return 1;
    }
    uVar7 = gost_get0_priv_key(uVar7);
    unaff_s2 = PTR___stack_chk_guard_006aabf0;
    unaff_s1 = *(undefined4 **)((int)register0x00000074 + -0xc);
    unaff_s0 = *(undefined **)((int)register0x00000074 + -0x10);
    *(undefined4 *)((int)register0x00000074 + -0x18) = *(undefined4 *)((int)register0x00000074 + -8)
    ;
    *(undefined4 *)((int)register0x00000074 + -8) = unaff_s6;
    *(undefined4 **)((int)register0x00000074 + -0xc) = unaff_s5;
    *(undefined4 **)((int)register0x00000074 + -0x10) = unaff_s4;
    *(undefined **)((int)register0x00000074 + -0x1a0) = &_gp;
    *(undefined4 *)((int)register0x00000074 + -4) = *(undefined4 *)((int)register0x00000074 + -4);
    *(undefined **)((int)register0x00000074 + -0x14) = unaff_s3;
    *(undefined4 **)((int)register0x00000074 + -0x1c) = unaff_s1;
    *(undefined **)((int)register0x00000074 + -0x20) = unaff_s0;
    *(undefined4 *)((int)register0x00000074 + -0x24) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    param_2 = puVar6;
    param_3 = puVar9;
    puVar2 = (undefined4 *)(*(code *)PTR_DH_new_006a8618)();
    puVar11 = *(undefined **)((int)register0x00000074 + -0x1a0);
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = 0;
    }
    else {
      unaff_s3 = (undefined *)((int)register0x00000074 + -0x124);
      (**(code **)(puVar11 + -0x53e0))(unaff_s3,0,0x80);
      unaff_s0 = (undefined *)((int)register0x00000074 + -0xa4);
      uVar3 = (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6de0))
                        (*(undefined4 *)(puVar6[5] + 0x14));
      iVar12 = *(int *)((int)register0x00000074 + -0x1a0);
      puVar2[3] = uVar3;
      uVar3 = (**(code **)(iVar12 + -0x6de0))(*(undefined4 *)(puVar6[5] + 0xc));
      pcVar10 = *(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6de0);
      puVar2[2] = uVar3;
      uVar3 = (*pcVar10)(uVar7);
      pcVar10 = *(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x57fc);
      puVar2[6] = uVar3;
      iVar4 = (*pcVar10)(puVar6);
      param_2 = *(undefined4 **)(iVar4 + 0x18);
      param_3 = puVar2;
      puVar6 = (undefined4 *)
               (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x6db4))(unaff_s0);
      unaff_s1 = puVar2;
      if (puVar6 == (undefined4 *)0x0) {
        (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x78dc))(puVar2);
        uVar3 = 0;
        puVar11 = *(undefined **)((int)register0x00000074 + -0x1a0);
      }
      else {
        (**(code **)(*(int *)((int)register0x00000074 + -0x1a0) + -0x53e0))(unaff_s3,0,0x80);
        iVar13 = *(int *)((int)register0x00000074 + -0x1a0);
        if (0 < (int)puVar6) {
          puVar5 = unaff_s0 + (int)((int)puVar6 + -1);
          puVar8 = unaff_s3;
          do {
            uVar1 = *puVar5;
            puVar5 = puVar5 + -1;
            *puVar8 = uVar1;
            puVar8 = puVar8 + 1;
          } while (puVar5 != (undefined *)((int)register0x00000074 + -0xa5));
        }
        unaff_s0 = (undefined *)((int)register0x00000074 + -0x198);
        (**(code **)(iVar13 + -0x78dc))(puVar2);
        init_gost_hash_ctx(unaff_s0,*(undefined4 *)
                                     (*(int *)((int)register0x00000074 + -0x1a0) + -0x5808));
        start_hash(unaff_s0);
        param_3 = (undefined4 *)&DAT_00000080;
        hash_block(unaff_s0,unaff_s3);
        param_2 = puVar9;
        finish_hash(unaff_s0);
        done_gost_hash_ctx(unaff_s0);
        uVar3 = 1;
        puVar11 = *(undefined **)((int)register0x00000074 + -0x1a0);
      }
    }
    param_1 = *(int *)((int)register0x00000074 + -0x24);
    if (param_1 == *(int *)unaff_s2) break;
    unaff_retaddr = pkey_gost94_derive;
    (**(code **)(puVar11 + -0x5328))();
    unaff_s4 = puVar9;
    unaff_s5 = puVar6;
    unaff_s6 = uVar7;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x1b0);
  }
  return uVar3;
}

