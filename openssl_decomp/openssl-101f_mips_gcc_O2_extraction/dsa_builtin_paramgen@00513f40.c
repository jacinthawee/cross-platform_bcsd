
undefined4
dsa_builtin_paramgen
          (int param_1,uint param_2,uint param_3,int param_4,int param_5,uint param_6,int param_7,
          int *param_8,int *param_9,BN_GENCB *param_10)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  BIGNUM *a;
  BIGNUM *ret;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  BIGNUM *a_01;
  BIGNUM *pBVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  BIGNUM *pBVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint num;
  int local_11c;
  BN_CTX *local_100;
  BIGNUM *local_f0;
  BN_MONT_CTX *local_ec;
  BIGNUM *local_e8;
  int local_e0;
  int local_dc;
  BIGNUM *local_d8;
  BIGNUM *local_d4;
  BIGNUM *local_bc;
  BIGNUM *local_b8;
  int local_b4;
  BIGNUM BStack_ac;
  byte bStack_8d;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  undefined auStack_6c [32];
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  num = param_3 >> 3;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((num & 0xfffffff7) != 0x14) && (uVar3 = 0, num != 0x20)) goto LAB_00513fe0;
  local_11c = param_4;
  if (param_4 == 0) {
    local_11c = (*(code *)PTR_EVP_sha1_006a86c4)();
  }
  if (param_2 < 0x200) {
    uVar13 = 0x200;
    if (param_6 == 0) goto LAB_00514084;
LAB_0051403c:
    if (num <= param_6) {
      if (num < param_6) {
        param_6 = num;
      }
      goto LAB_00514084;
    }
    if (num < param_6) {
      param_6 = num;
    }
    local_100 = BN_CTX_new();
  }
  else {
    uVar13 = param_2 + 0x3f & 0xffffffc0;
    if (param_6 != 0) goto LAB_0051403c;
LAB_00514084:
    if (param_5 != 0) {
      (*(code *)PTR___memcpy_chk_006aab54)(&BStack_ac,param_5,param_6,0x20);
    }
    local_100 = BN_CTX_new();
  }
  if (local_100 != (BN_CTX *)0x0) {
    local_ec = BN_MONT_CTX_new();
    if (local_ec == (BN_MONT_CTX *)0x0) goto LAB_0051479c;
    uVar13 = uVar13 - 1;
    BN_CTX_start(local_100);
    local_d8 = BN_CTX_get(local_100);
    pBVar9 = BN_CTX_get(local_100);
    a = BN_CTX_get(local_100);
    ret = BN_CTX_get(local_100);
    a_00 = BN_CTX_get(local_100);
    pBVar4 = BN_CTX_get(local_100);
    a_01 = BN_CTX_get(local_100);
    local_d4 = BN_CTX_get(local_100);
    pBVar5 = BN_value_one();
    iVar8 = BN_lshift(local_d4,pBVar5,uVar13);
    local_f0 = a;
    if (iVar8 == 0) goto LAB_0051479c;
    local_e0 = 0;
    uVar12 = num - 1;
    iVar8 = (num - 4 >> 2) + 1;
    do {
      iVar10 = BN_GENCB_call(param_10,0,local_e0);
      local_e8 = ret;
      local_bc = a_01;
      local_b8 = pBVar9;
      local_b4 = param_1;
      if (iVar10 == 0) goto LAB_0051479c;
      local_f0 = &BStack_ac;
      if (param_6 == 0) {
        RAND_pseudo_bytes((uchar *)local_f0,num);
      }
      (*(code *)PTR___memcpy_chk_006aab54)(auStack_6c,local_f0,num,0x20);
      (*(code *)PTR___memcpy_chk_006aab54)(&local_4c,local_f0,num,0x20);
      if ((uVar12 != 0xffffffff) &&
         (cVar1 = auStack_6c[num - 1], auStack_6c[num - 1] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar11 = auStack_6c + (num - 2);
        do {
          if (pcVar11 == (char *)((int)&local_70 + 3)) break;
          cVar1 = *pcVar11;
          *pcVar11 = cVar1 + '\x01';
          pcVar11 = pcVar11 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      iVar10 = (*(code *)PTR_EVP_Digest_006a8b04)(local_f0,num,&local_8c,0,local_11c,0);
      if (iVar10 == 0) goto LAB_0051479c;
      iVar10 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_6c,num,&local_4c,0,local_11c,0);
      if (iVar10 == 0) goto LAB_0051479c;
      if (num != 0) {
        if (uVar12 < 3) {
          uVar7 = 0;
        }
        else {
          local_8c = local_4c ^ local_8c;
          if (((((iVar8 != 1) && (local_88 = local_48 ^ local_88, iVar8 != 2)) &&
               (local_84 = local_84 ^ local_44, iVar8 != 3)) &&
              ((local_80 = local_80 ^ local_40, iVar8 != 4 &&
               (local_7c = local_7c ^ local_3c, iVar8 != 5)))) &&
             ((local_78 = local_78 ^ local_38, iVar8 != 6 &&
              (local_74 = local_74 ^ local_34, iVar8 != 7)))) {
            local_70 = local_70 ^ local_30;
          }
          uVar7 = iVar8 * 4;
          if (num == iVar8 * 4) goto LAB_00514484;
        }
        *(byte *)((int)&local_8c + uVar7) =
             *(byte *)((int)&local_4c + uVar7) ^ *(byte *)((int)&local_8c + uVar7);
        if ((int)(uVar7 + 1) < (int)num) {
          *(byte *)((int)&local_8c + uVar7 + 1) =
               *(byte *)((int)&local_4c + uVar7 + 1) ^ *(byte *)((int)&local_8c + uVar7 + 1);
          if ((int)(uVar7 + 2) < (int)num) {
            *(byte *)((int)&local_8c + uVar7 + 2) =
                 *(byte *)((int)&local_8c + uVar7 + 2) ^ *(byte *)((int)&local_4c + uVar7 + 2);
          }
        }
      }
LAB_00514484:
      local_8c = local_8c | 0x80000000;
      (&bStack_8d)[num] = (&bStack_8d)[num] | 1;
      pBVar5 = BN_bin2bn((uchar *)&local_8c,num,ret);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_0051479c;
      iVar10 = BN_is_prime_fasttest_ex(ret,0x32,local_100,(uint)(param_6 == 0),param_10);
      if (0 < iVar10) {
        iVar10 = BN_GENCB_call(param_10,2,0);
        if (iVar10 == 0) goto LAB_0051479c;
        iVar10 = BN_GENCB_call(param_10,3,0);
        if (iVar10 == 0) goto LAB_0051479c;
        local_dc = 0;
        do {
          iVar10 = 0;
          BN_set_word(a,0);
          iVar14 = 0;
          do {
            if ((uVar12 != 0xffffffff) &&
               (cVar1 = auStack_6c[num - 1], auStack_6c[num - 1] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar11 = auStack_6c + (num - 2);
              do {
                if ((char *)((int)&local_70 + 3) == pcVar11) break;
                cVar1 = *pcVar11;
                *pcVar11 = cVar1 + '\x01';
                pcVar11 = pcVar11 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar6 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_6c,num,&local_8c,0,local_11c,0);
            if (iVar6 == 0) goto LAB_0051479c;
            pBVar5 = BN_bin2bn((uchar *)&local_8c,num,local_d8);
            if (pBVar5 == (BIGNUM *)0x0) goto LAB_0051479c;
            iVar6 = BN_lshift(local_d8,local_d8,iVar10);
            if (iVar6 == 0) goto LAB_0051479c;
            iVar6 = (*(code *)PTR_BN_add_006a96c8)(a,a,local_d8);
            if (iVar6 == 0) goto LAB_0051479c;
            iVar14 = iVar14 + 1;
            iVar10 = iVar10 + (param_3 & 0xfffffff8);
          } while (iVar14 <= (int)(uVar13 / 0xa0));
          iVar10 = BN_mask_bits(a,uVar13);
          if (iVar10 == 0) goto LAB_0051479c;
          pBVar5 = BN_copy(a_00,a);
          if (pBVar5 == (BIGNUM *)0x0) goto LAB_0051479c;
          iVar10 = (*(code *)PTR_BN_add_006a96c8)(a_00,a_00,local_d4);
          if (iVar10 == 0) goto LAB_0051479c;
          iVar10 = BN_lshift1(local_d8,ret);
          if (iVar10 == 0) goto LAB_0051479c;
          iVar10 = (*(code *)PTR_BN_div_006a967c)(0,pBVar4,a_00,local_d8,local_100);
          if (iVar10 == 0) goto LAB_0051479c;
          pBVar5 = BN_value_one();
          iVar10 = (*(code *)PTR_BN_sub_006a96cc)(local_d8,pBVar4,pBVar5);
          if (iVar10 == 0) goto LAB_0051479c;
          iVar10 = (*(code *)PTR_BN_sub_006a96cc)(a_01,a_00,local_d8);
          if (iVar10 == 0) goto LAB_0051479c;
          iVar10 = BN_cmp(a_01,local_d4);
          if (-1 < iVar10) {
            iVar10 = BN_is_prime_fasttest_ex(a_01,0x32,local_100,1,param_10);
            if (0 < iVar10) goto LAB_0051484c;
            if (iVar10 != 0) goto LAB_0051479c;
          }
          local_dc = local_dc + 1;
          if (local_dc == 0x1000) goto LAB_005144ec;
          iVar10 = BN_GENCB_call(param_10,0,local_dc);
          if (iVar10 == 0) goto LAB_0051479c;
        } while( true );
      }
      if (iVar10 != 0) goto LAB_0051479c;
LAB_005144ec:
      param_6 = 0;
      local_e0 = local_e0 + 1;
    } while( true );
  }
  uVar3 = 0;
LAB_00513fe0:
  do {
    if (local_2c == *(int *)puVar2) {
      return uVar3;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0051484c:
    iVar8 = BN_GENCB_call(param_10,2,1);
    if (iVar8 != 0) {
      pBVar9 = BN_value_one();
      iVar8 = (*(code *)PTR_BN_sub_006a96cc)(local_d4,local_bc,pBVar9);
      if ((((iVar8 != 0) &&
           (iVar8 = (*(code *)PTR_BN_div_006a967c)(local_d8,0,local_d4,local_e8,local_100),
           iVar8 != 0)) && (iVar8 = BN_set_word(local_d4,2), iVar8 != 0)) &&
         (iVar8 = BN_MONT_CTX_set(local_ec,local_bc,local_100), iVar8 != 0)) {
        iVar8 = 2;
        while (iVar10 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                                  (local_b8,local_d4,local_d8,local_bc,local_100,local_ec),
              iVar10 != 0) {
          if (((local_b8->top != 1) || (*local_b8->d != 1)) || (local_b8->neg != 0)) {
            iVar10 = BN_GENCB_call(param_10,3,1);
            if (iVar10 != 0) {
              if (*(BIGNUM **)(local_b4 + 0xc) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(local_b4 + 0xc));
              }
              if (*(BIGNUM **)(local_b4 + 0x10) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(local_b4 + 0x10));
              }
              if (*(BIGNUM **)(local_b4 + 0x14) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(local_b4 + 0x14));
              }
              pBVar9 = BN_dup(local_bc);
              *(BIGNUM **)(local_b4 + 0xc) = pBVar9;
              pBVar9 = BN_dup(local_e8);
              *(BIGNUM **)(local_b4 + 0x10) = pBVar9;
              pBVar9 = BN_dup(local_b8);
              *(BIGNUM **)(local_b4 + 0x14) = pBVar9;
              if (*(int *)(local_b4 + 0xc) != 0) {
                uVar3 = 0;
                if ((*(int *)(local_b4 + 0x10) != 0) && (pBVar9 != (BIGNUM *)0x0)) {
                  if (param_8 != (int *)0x0) {
                    *param_8 = local_dc;
                  }
                  if (param_9 != (int *)0x0) {
                    *param_9 = iVar8;
                  }
                  if (param_7 == 0) {
                    uVar3 = 1;
                  }
                  else {
                    uVar3 = 1;
                    (*(code *)PTR_memcpy_006aabf4)(param_7,local_f0,num);
                  }
                }
                goto LAB_005147a0;
              }
            }
            break;
          }
          pBVar9 = BN_value_one();
          iVar10 = (*(code *)PTR_BN_add_006a96c8)(local_d4,local_d4,pBVar9);
          if (iVar10 == 0) break;
          iVar8 = iVar8 + 1;
        }
      }
    }
LAB_0051479c:
    uVar3 = 0;
LAB_005147a0:
    BN_CTX_end(local_100);
    BN_CTX_free(local_100);
    if (local_ec != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(local_ec);
    }
  } while( true );
}

