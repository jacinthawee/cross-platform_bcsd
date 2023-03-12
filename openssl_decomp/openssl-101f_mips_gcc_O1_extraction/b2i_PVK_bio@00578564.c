
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
  int unaff_s1;
  uint uVar8;
  code *pcVar9;
  undefined4 uStack_80;
  int iStack_7c;
  EVP_PKEY *pEStack_78;
  int iStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  void *local_58;
  undefined *local_50;
  uint local_44 [3];
  int local_38;
  EVP_PKEY *local_34;
  uint local_30;
  int local_2c;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_50 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_read_006a85bc)(in,local_44,0x18);
  if (iVar3 == 0x18) {
    if ((((local_44[0] >> 0x10) << 0x18 | (local_44[0] >> 0x18) << 0x10) >> 0x10) +
        ((local_44[0] & 0xff) << 8 | local_44[0] >> 8 & 0xff) * 0x10000 == -0x4f4a0ee2) {
      uVar8 = (local_30 & 0xff) << 8 | local_30 >> 8 & 0xff;
      unaff_s0 = (EVP_PKEY *)
                 (((((uint)local_34 >> 0x10) << 0x18 | ((uint)local_34 >> 0x18) << 0x10) >> 0x10) +
                 (((uint)local_34 & 0xff) << 8 | (uint)local_34 >> 8 & 0xff) * 0x10000);
      uVar1 = ((local_30 >> 0x10) << 0x18 | (local_30 >> 0x18) << 0x10) >> 0x10;
      if ((local_38 == 0) || (unaff_s0 != (EVP_PKEY *)0x0)) {
        iVar3 = (int)&unaff_s0[uVar8 * 0x800].type + uVar1;
        unaff_s1 = (**(code **)(local_50 + -0x7dd8))(iVar3,FUN_0066ce6c,0x336);
        if (unaff_s1 == 0) {
          local_58 = (void *)0x339;
          (**(code **)(local_50 + -0x6eb0))(9,0x80,0x41,FUN_0066ce6c);
          pEVar7 = (EVP_PKEY *)0x0;
        }
        else {
          iVar4 = (**(code **)(local_50 + -0x7924))(in,unaff_s1,iVar3);
          if (iVar3 == iVar4) {
            local_58 = u;
            pEVar7 = (EVP_PKEY *)do_PVK_body_isra_3(unaff_s1,unaff_s0,uVar1 + uVar8 * 0x10000,cb);
          }
          else {
            local_58 = (void *)0x33f;
            pEVar7 = (EVP_PKEY *)0x0;
            (**(code **)(local_50 + -0x6eb0))(9,0x80,0x7c,FUN_0066ce6c);
          }
          (**(code **)(local_50 + -0x7d6c))(unaff_s1,iVar3);
          (**(code **)(local_50 + -0x7f58))(unaff_s1);
          unaff_s0 = pEVar7;
        }
        goto LAB_005786d8;
      }
      pcVar9 = *(code **)(local_50 + -0x6eb0);
      uVar6 = 0x79;
      local_58 = (void *)0x2bb;
    }
    else {
      pcVar9 = *(code **)(local_50 + -0x6eb0);
      uVar6 = 0x74;
      local_58 = (void *)0x2ae;
      unaff_s0 = local_34;
    }
    (*pcVar9)(9,0x88,uVar6,FUN_0066ce6c);
    pEVar7 = (EVP_PKEY *)0x0;
  }
  else {
    local_58 = (void *)0x32e;
    (**(code **)(local_50 + -0x6eb0))(9,0x80,0x7c,FUN_0066ce6c);
    pEVar7 = (EVP_PKEY *)0x0;
  }
LAB_005786d8:
  if (local_2c == *(int *)puStack_70) {
    return pEVar7;
  }
  pcStack_6c = i2b_PVK_bio;
  iVar3 = local_2c;
  (**(code **)(local_50 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  uStack_80 = 0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_78 = unaff_s0;
  iStack_74 = unaff_s1;
  pEVar7 = (EVP_PKEY *)i2b_PVK_constprop_4(&uStack_80);
  if (-1 < (int)pEVar7) {
    pEVar5 = (EVP_PKEY *)(*(code *)PTR_BIO_write_006a7f14)(iVar3,uStack_80,pEVar7);
    (*(code *)PTR_CRYPTO_free_006a7f88)(uStack_80);
    if (pEVar7 == pEVar5) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x8a,0x76,FUN_0066ce6c,0x3ae);
      goto LAB_00578864;
    }
  }
  pEVar7 = (EVP_PKEY *)0xffffffff;
LAB_00578864:
  if (iStack_7c == *(int *)puVar2) {
    return pEVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (EVP_PKEY *)"/usr/local/openssl101fmipso1/private";
}

