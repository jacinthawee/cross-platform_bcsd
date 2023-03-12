
int ssl2_generate_key_material(undefined *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int unaff_s1;
  int unaff_s3;
  int unaff_s4;
  code *pcVar7;
  undefined auStack_d0 [4];
  int iStack_cc;
  undefined4 *puStack_c8;
  undefined *puStack_c4;
  undefined *puStack_c0;
  int iStack_bc;
  int iStack_b8;
  code *pcStack_b4;
  undefined4 uStack_a0;
  undefined4 *puStack_9c;
  undefined4 uStack_98;
  undefined *puStack_90;
  undefined uStack_88;
  undefined uStack_87;
  undefined uStack_86;
  int iStack_84;
  undefined4 *puStack_80;
  int iStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  undefined4 local_60;
  undefined *local_58;
  char *local_4c;
  char local_45;
  undefined4 auStack_44 [6];
  undefined4 *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_45 = '0';
  puStack_80 = auStack_44;
  local_58 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_EVP_md5_006a81c8)();
  (**(code **)(local_58 + -0x7fc4))(puStack_80);
  if (*(uint *)(*(int *)(param_1 + 0xc0) + 0x10) < 0x31) {
    unaff_s4 = *(int *)(param_1 + 0x54);
    unaff_s3 = (**(code **)(local_58 + -0x6fb4))(uVar2);
    if (unaff_s3 < 0) {
      iVar3 = 0;
      goto LAB_0047c77c;
    }
    pcVar7 = *(code **)(local_58 + -0x7fac);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x9c) == 0) {
LAB_0047c7bc:
      (*pcVar7)(puStack_80);
      iVar3 = 1;
      goto LAB_0047c77c;
    }
    iVar3 = unaff_s4 - *(int *)(param_1 + 0x54);
    unaff_s4 = unaff_s4 + 0xa0;
    if (iVar3 + unaff_s3 < 0x31) {
      local_4c = "s2_lib.c";
      param_2 = unaff_s4;
      do {
        (**(code **)(local_58 + -0x7870))(puStack_80,uVar2,0);
        iVar3 = *(int *)(param_1 + 0xc0);
        uVar6 = *(uint *)(iVar3 + 0x10);
        if (0x2f < uVar6) {
          (**(code **)(local_58 + -0x7194))
                    (local_4c,0x1e9,
                     "s->session->master_key_length >= 0 && s->session->master_key_length < (int)sizeof(s->session->master_key)"
                    );
          iVar3 = *(int *)(param_1 + 0xc0);
          uVar6 = *(uint *)(iVar3 + 0x10);
        }
        (**(code **)(local_58 + -0x786c))(puStack_80,iVar3 + 0x14,uVar6);
        (**(code **)(local_58 + -0x786c))(puStack_80,&local_45,1);
        local_45 = local_45 + '\x01';
        (**(code **)(local_58 + -0x786c))
                  (puStack_80,*(int *)(param_1 + 0x54) + 0x68,
                   *(undefined4 *)(*(int *)(param_1 + 0x54) + 100));
        (**(code **)(local_58 + -0x786c))
                  (puStack_80,*(int *)(param_1 + 0x54) + 0x8c,
                   *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x88));
        unaff_s1 = param_2 + unaff_s3;
        (**(code **)(local_58 + -0x7868))(puStack_80,param_2,0);
        if (*(uint *)(*(int *)(param_1 + 0x54) + 0x9c) <= (uint)(unaff_s1 - unaff_s4)) {
          pcVar7 = *(code **)(local_58 + -0x7fac);
          goto LAB_0047c7bc;
        }
        param_2 = unaff_s1;
      } while ((unaff_s1 - (*(int *)(param_1 + 0x54) + 0xa0)) + unaff_s3 < 0x31);
    }
    pcVar7 = *(code **)(local_58 + -0x6eb0);
    local_60 = 0x1e1;
  }
  else {
    pcVar7 = *(code **)(local_58 + -0x6eb0);
    local_60 = 0x1d5;
  }
  param_2 = 0xf1;
  (*pcVar7)(0x14,0xf1,0x44,"s2_lib.c");
  iVar3 = 0;
LAB_0047c77c:
  if (local_2c == *(undefined4 **)puVar1) {
    return iVar3;
  }
  pcStack_74 = ssl2_return_error;
  puVar5 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  puStack_90 = &_gp;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar4 = puVar5;
  puStack_c8 = puStack_80;
  puStack_c0 = param_1;
  iStack_7c = unaff_s1;
  puStack_78 = param_1;
  if (puVar5[0x35] == 0) {
    puStack_c0 = &uStack_88;
    puVar5[0x36] = param_2;
    puVar5[0x35] = 0;
    uStack_88 = 0;
    uStack_87 = (undefined)((uint)param_2 >> 8);
    uStack_86 = (undefined)param_2;
    iVar3 = ssl2_write();
    puStack_c8 = puVar5;
    if (iVar3 < 0) {
      puVar5[0x35] = 3;
    }
    else {
      puVar5[0x35] = 3 - iVar3;
      if ((3 - iVar3 == 0) && ((code *)puVar5[0x19] != (code *)0x0)) {
        uStack_98 = puVar5[0x1a];
        puVar4 = (undefined4 *)0x1;
        uStack_a0 = 3;
        puStack_9c = puVar5;
        (*(code *)puVar5[0x19])(1,*puVar5,0,puStack_c0);
      }
    }
  }
  iVar3 = *(int *)puStack_c4;
  if (iStack_84 != iVar3) {
    pcStack_b4 = ssl2_write_error;
    (**(code **)(puStack_90 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    uVar6 = puVar4[0x35];
    auStack_d0[0] = 0;
    puVar4[0x35] = 0;
    auStack_d0[2] = (undefined)puVar4[0x36];
    auStack_d0[1] = (undefined)((uint)puVar4[0x36] >> 8);
    iStack_cc = *(int *)puVar1;
    iStack_bc = unaff_s3;
    iStack_b8 = unaff_s4;
    if (3 < uVar6) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("s2_lib.c",0x210,"error >= 0 && error <= (int)sizeof(buf)")
      ;
    }
    puVar5 = puVar4;
    iVar3 = ssl2_write(puVar4,auStack_d0 + (3 - uVar6),uVar6);
    if (iVar3 < 0) {
      puVar4[0x35] = uVar6;
    }
    else {
      puVar4[0x35] = uVar6 - iVar3;
      if ((uVar6 - iVar3 == 0) && ((code *)puVar4[0x19] != (code *)0x0)) {
        puVar5 = (undefined4 *)0x1;
        (*(code *)puVar4[0x19])(1,*puVar4,0,auStack_d0,3,puVar4,puVar4[0x1a]);
      }
    }
    iVar3 = *(int *)puVar1;
    if (iStack_cc != iVar3) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar5[0xc] = 3;
      return 1;
    }
    return iVar3;
  }
  return iVar3;
}

