
EVP_PKEY * b2i_PVK_bio(BIO *in,undefined1 *cb,void *u)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  EVP_PKEY *pEVar5;
  undefined4 uVar6;
  EVP_PKEY *unaff_s0;
  EVP_PKEY *pEVar7;
  uint unaff_s1;
  uint uVar8;
  int iVar9;
  code *pcVar10;
  undefined4 uStack_80;
  int iStack_7c;
  EVP_PKEY *pEStack_78;
  uint uStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  void *local_58;
  undefined *local_50;
  uint local_44 [3];
  uint local_38;
  uint local_34;
  EVP_PKEY *local_30;
  int local_2c;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  local_50 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BIO_read_006a74c0)(in,local_44,0x18);
  if (iVar3 == 0x18) {
    if ((((local_44[0] >> 0x10) << 0x18 | (local_44[0] >> 0x18) << 0x10) >> 0x10) +
        ((local_44[0] & 0xff) << 8 | local_44[0] >> 8 & 0xff) * 0x10000 == -0x4f4a0ee2) {
      unaff_s0 = (EVP_PKEY *)
                 (((((uint)local_30 >> 0x10) << 0x18 | ((uint)local_30 >> 0x18) << 0x10) >> 0x10) +
                 (((uint)local_30 & 0xff) << 8 | (uint)local_30 >> 8 & 0xff) * 0x10000);
      uVar8 = (local_34 & 0xff) << 8 | local_34 >> 8 & 0xff;
      uVar1 = ((local_34 >> 0x10) << 0x18 | (local_34 >> 0x18) << 0x10) >> 0x10;
      unaff_s1 = uVar1 + uVar8 * 0x10000;
      if ((unaff_s0 < (EVP_PKEY *)0x19001) && (unaff_s1 < 0x2801)) {
        if (((((local_38 >> 0x10) << 0x18 | (local_38 >> 0x18) << 0x10) >> 0x10) +
             ((local_38 & 0xff) << 8 | local_38 >> 8 & 0xff) * 0x10000 == 0) || (unaff_s1 != 0)) {
          iVar9 = (int)&unaff_s0[uVar8 * 0x800].type + uVar1;
          iVar3 = (**(code **)(local_50 + -0x7dd8))(iVar9,FUN_0066c47c,0x30a);
          if (iVar3 == 0) {
            local_58 = (void *)0x30c;
            (**(code **)(local_50 + -0x6eac))(9,0x80,0x41,FUN_0066c47c);
            pEVar7 = (EVP_PKEY *)0x0;
          }
          else {
            iVar4 = (**(code **)(local_50 + -0x7920))(in,iVar3,iVar9);
            if (iVar9 == iVar4) {
              local_58 = u;
              pEVar7 = (EVP_PKEY *)do_PVK_body_isra_3(iVar3,unaff_s1,unaff_s0,cb);
            }
            else {
              local_58 = (void *)0x311;
              pEVar7 = (EVP_PKEY *)0x0;
              (**(code **)(local_50 + -0x6eac))(9,0x80,0x7c,FUN_0066c47c);
            }
            (**(code **)(local_50 + -0x7d6c))(iVar3,iVar9);
            (**(code **)(local_50 + -0x7f58))(iVar3);
            unaff_s0 = pEVar7;
          }
          goto LAB_00574eb8;
        }
        pcVar10 = *(code **)(local_50 + -0x6eac);
        uVar6 = 0x79;
        local_58 = (void *)0x296;
        goto LAB_00574ea0;
      }
    }
    else {
      pcVar10 = *(code **)(local_50 + -0x6eac);
      uVar6 = 0x74;
      local_58 = (void *)0x285;
      unaff_s0 = local_30;
LAB_00574ea0:
      (*pcVar10)(9,0x88,uVar6,FUN_0066c47c);
    }
    pEVar7 = (EVP_PKEY *)0x0;
  }
  else {
    local_58 = (void *)0x302;
    (**(code **)(local_50 + -0x6eac))(9,0x80,0x7c,FUN_0066c47c);
    pEVar7 = (EVP_PKEY *)0x0;
  }
LAB_00574eb8:
  if (local_2c == *(int *)puStack_70) {
    return pEVar7;
  }
  pcStack_6c = i2b_PVK_bio;
  iVar3 = local_2c;
  (**(code **)(local_50 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uStack_80 = 0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEStack_78 = unaff_s0;
  uStack_74 = unaff_s1;
  pEVar7 = (EVP_PKEY *)i2b_PVK_constprop_4(&uStack_80);
  if (-1 < (int)pEVar7) {
    pEVar5 = (EVP_PKEY *)(*(code *)PTR_BIO_write_006a6e14)(iVar3,uStack_80,pEVar7);
    (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_80);
    if (pEVar7 == pEVar5) {
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x8a,0x76,FUN_0066c47c,0x377);
      goto LAB_00575044;
    }
  }
  pEVar7 = (EVP_PKEY *)0xffffffff;
LAB_00575044:
  if (iStack_7c == *(int *)puVar2) {
    return pEVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (EVP_PKEY *)"/usr/local/openssl101umipso1/private";
}

