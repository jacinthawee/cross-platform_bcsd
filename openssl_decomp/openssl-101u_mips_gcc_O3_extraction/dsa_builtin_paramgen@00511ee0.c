
int dsa_builtin_paramgen
              (int param_1,uint param_2,uint param_3,EVP_MD *param_4,int param_5,uint param_6,
              int param_7,int *param_8,BIGNUM **param_9,BN_GENCB *param_10)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined *n;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *pBVar5;
  int iVar6;
  BIGNUM *pBVar7;
  int iVar8;
  uint uVar9;
  BIGNUM *pBVar10;
  BIGNUM *pBVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  BIGNUM *unaff_s1;
  BIGNUM *unaff_s2;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  uint count;
  EVP_MD *local_11c;
  int local_10c;
  BN_MONT_CTX *local_f0;
  BIGNUM *local_ec;
  uchar *local_e8;
  int local_dc;
  int local_d8;
  uchar auStack_ac [31];
  byte bStack_8d;
  undefined local_8c [2];
  byte abStack_8a [2];
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  count = param_3 >> 3;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pBVar11 = unaff_s3;
  if (((count & 0xfffffff7) != 0x14) && (iVar3 = 0, count != 0x20)) goto LAB_00511f80;
  local_11c = param_4;
  if (param_4 == (EVP_MD *)0x0) {
    local_11c = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if (param_2 < 0x200) {
    unaff_s1 = (BIGNUM *)0x200;
    if (param_6 != 0) goto LAB_00511fe4;
LAB_0051202c:
    if (param_5 != 0) {
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_ac,param_5,param_6,0x20);
    }
    local_f0 = BN_MONT_CTX_new();
  }
  else {
    unaff_s1 = (BIGNUM *)(param_2 + 0x3f & 0xffffffc0);
    if (param_6 == 0) goto LAB_0051202c;
LAB_00511fe4:
    if (count <= param_6) {
      if (count < param_6) {
        param_6 = count;
      }
      goto LAB_0051202c;
    }
    local_10c = 0;
    if (count < param_6) {
      param_6 = count;
    }
    local_f0 = BN_MONT_CTX_new();
    param_5 = local_10c;
  }
  if (local_f0 != (BN_MONT_CTX *)0x0) {
    pBVar10 = (BIGNUM *)BN_CTX_new();
    local_ec = pBVar10;
    if (pBVar10 == (BIGNUM *)0x0) {
      iVar3 = 0;
      goto LAB_00512778;
    }
    n = (undefined *)((int)&unaff_s1[-1].flags + 3);
    BN_CTX_start((BN_CTX *)pBVar10);
    ret = BN_CTX_get((BN_CTX *)pBVar10);
    pBVar11 = BN_CTX_get((BN_CTX *)pBVar10);
    unaff_s4 = BN_CTX_get((BN_CTX *)pBVar10);
    unaff_s1 = BN_CTX_get((BN_CTX *)pBVar10);
    a = BN_CTX_get((BN_CTX *)pBVar10);
    pBVar4 = BN_CTX_get((BN_CTX *)pBVar10);
    unaff_s2 = BN_CTX_get((BN_CTX *)pBVar10);
    r = BN_CTX_get((BN_CTX *)pBVar10);
    pBVar5 = BN_value_one();
    iVar3 = BN_lshift(r,pBVar5,(int)n);
    pBVar5 = unaff_s2;
    unaff_s3 = pBVar11;
    if (iVar3 == 0) goto LAB_00512750;
    local_dc = 0;
    uVar14 = count - 1;
    iVar12 = (count - 4 >> 2) + 1;
    local_e8 = auStack_ac;
    pBVar5 = (BIGNUM *)((int)&local_2c + count + 3);
    do {
      iVar3 = BN_GENCB_call(param_10,0,local_dc);
      if (iVar3 == 0) goto LAB_00512750;
      if ((param_6 == 0) || (iVar3 = 0, param_5 == 0)) {
        iVar3 = RAND_bytes(local_e8,count);
        if (iVar3 < 1) goto LAB_00512750;
        iVar3 = 1;
      }
      else {
        param_6 = 0;
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_6c,local_e8,count,0x20);
      (*(code *)PTR___memcpy_chk_006a9a48)(&local_4c,local_e8,count,0x20);
      if ((uVar14 != 0xffffffff) &&
         (cVar1 = auStack_6c[count - 1], auStack_6c[count - 1] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar13 = auStack_6c + (count - 2);
        do {
          if (pcVar13 == (char *)((int)&local_70 + 3)) break;
          cVar1 = *pcVar13;
          *pcVar13 = cVar1 + '\x01';
          pcVar13 = pcVar13 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      unaff_s3 = (BIGNUM *)local_8c;
      iVar6 = (*(code *)PTR_EVP_Digest_006a7a14)(local_e8,count,unaff_s3,0,local_11c,0);
      if (iVar6 == 0) goto LAB_00512750;
      iVar6 = (*(code *)PTR_EVP_Digest_006a7a14)(auStack_6c,count,&local_4c,0,local_11c,0);
      if (iVar6 == 0) goto LAB_00512750;
      if (count != 0) {
        if (uVar14 < 3) {
          uVar9 = 0;
        }
        else {
          _local_8c = (ulong *)(local_4c ^ (uint)_local_8c);
          if (((((iVar12 != 1) && (local_88 = local_48 ^ local_88, iVar12 != 2)) &&
               (local_84 = local_84 ^ local_44, iVar12 != 3)) &&
              ((local_80 = local_80 ^ local_40, iVar12 != 4 &&
               (local_7c = local_7c ^ local_3c, iVar12 != 5)))) &&
             ((local_78 = local_78 ^ local_38, iVar12 != 6 &&
              (local_74 = local_74 ^ local_34, iVar12 != 7)))) {
            local_70 = local_70 ^ local_30;
          }
          uVar9 = iVar12 * 4;
          if (count == iVar12 * 4) goto LAB_00512438;
        }
        local_8c[uVar9] = local_8c[uVar9] ^ *(byte *)((int)&local_4c + uVar9);
        if ((int)(uVar9 + 1) < (int)count) {
          local_8c[uVar9 + 1] = local_8c[uVar9 + 1] ^ *(byte *)((int)&local_4c + uVar9 + 1);
          if ((int)(uVar9 + 2) < (int)count) {
            local_8c[uVar9 + 2] = local_8c[uVar9 + 2] ^ *(byte *)((int)&local_4c + uVar9 + 2);
          }
        }
      }
LAB_00512438:
      _local_8c = (ulong *)((uint)_local_8c | 0x80000000);
      (&bStack_8d)[count] = (&bStack_8d)[count] | 1;
      pBVar7 = BN_bin2bn((uchar *)unaff_s3,count,unaff_s1);
      if (pBVar7 == (BIGNUM *)0x0) goto LAB_00512750;
      iVar6 = BN_is_prime_fasttest_ex(unaff_s1,0x32,(BN_CTX *)pBVar10,iVar3,param_10);
      if (0 < iVar6) {
        iVar3 = BN_GENCB_call(param_10,2,0);
        if (iVar3 == 0) goto LAB_00512750;
        iVar3 = BN_GENCB_call(param_10,3,0);
        if (iVar3 == 0) goto LAB_00512750;
        local_d8 = 0;
        do {
          iVar3 = 0;
          BN_set_word(unaff_s4,0);
          iVar6 = 0;
          do {
            if ((uVar14 != 0xffffffff) &&
               (cVar1 = auStack_6c[count - 1], auStack_6c[count - 1] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar13 = auStack_6c + (count - 2);
              do {
                if ((char *)((int)&local_70 + 3) == pcVar13) break;
                cVar1 = *pcVar13;
                *pcVar13 = cVar1 + '\x01';
                pcVar13 = pcVar13 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar8 = EVP_Digest(auStack_6c,count,(uchar *)unaff_s3,(uint *)0x0,local_11c,
                               (ENGINE *)0x0);
            if (iVar8 == 0) goto LAB_00512750;
            pBVar7 = BN_bin2bn((uchar *)unaff_s3,count,ret);
            if (pBVar7 == (BIGNUM *)0x0) goto LAB_00512750;
            iVar8 = BN_lshift(ret,ret,iVar3);
            if (iVar8 == 0) goto LAB_00512750;
            iVar8 = (*(code *)PTR_BN_add_006a85a4)(unaff_s4,unaff_s4,ret);
            if (iVar8 == 0) goto LAB_00512750;
            iVar6 = iVar6 + 1;
            iVar3 = iVar3 + (param_3 & 0xfffffff8);
          } while (iVar6 <= (int)((uint)n / 0xa0));
          iVar3 = BN_mask_bits(unaff_s4,(int)n);
          if (iVar3 == 0) goto LAB_00512750;
          pBVar7 = BN_copy(a,unaff_s4);
          if (pBVar7 == (BIGNUM *)0x0) goto LAB_00512750;
          iVar3 = (*(code *)PTR_BN_add_006a85a4)(a,a,r);
          if (iVar3 == 0) goto LAB_00512750;
          iVar3 = BN_lshift1(ret,unaff_s1);
          if (iVar3 == 0) goto LAB_00512750;
          iVar3 = (*(code *)PTR_BN_div_006a855c)(0,pBVar4,a,ret,pBVar10);
          if (iVar3 == 0) goto LAB_00512750;
          pBVar7 = BN_value_one();
          iVar3 = (*(code *)PTR_BN_sub_006a85a8)(ret,pBVar4,pBVar7);
          if (iVar3 == 0) goto LAB_00512750;
          iVar3 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s2,a,ret);
          if (iVar3 == 0) goto LAB_00512750;
          iVar3 = BN_cmp(unaff_s2,r);
          if (-1 < iVar3) {
            iVar6 = BN_is_prime_fasttest_ex(unaff_s2,0x32,(BN_CTX *)pBVar10,1,param_10);
            if (0 < iVar6) {
              iVar3 = BN_GENCB_call(param_10,2,1);
              pBVar5 = unaff_s2;
              unaff_s3 = pBVar11;
              if (iVar3 == 0) goto LAB_00512750;
              pBVar5 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a85a8)(r,unaff_s2,pBVar5);
              pBVar5 = unaff_s2;
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = (*(code *)PTR_BN_div_006a855c)(ret,0,r,unaff_s1,pBVar10);
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = BN_set_word(r,2);
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = BN_MONT_CTX_set(local_f0,unaff_s2,(BN_CTX *)pBVar10);
              if (iVar3 == 0) goto LAB_00512750;
              unaff_s4 = (BIGNUM *)&SUB_00000002;
              do {
                iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                                  (pBVar11,r,ret,unaff_s2,pBVar10,local_f0);
                pBVar5 = unaff_s2;
                if (iVar3 == 0) goto LAB_00512750;
                if (pBVar11->top != 1) goto LAB_0051294c;
                if (*pBVar11->d != 1) goto LAB_0051294c;
                if (pBVar11->neg != 0) goto LAB_0051294c;
                pBVar5 = BN_value_one();
                iVar3 = (*(code *)PTR_BN_add_006a85a4)(r,r,pBVar5);
                pBVar5 = unaff_s2;
                if (iVar3 == 0) goto LAB_00512750;
                unaff_s4 = (BIGNUM *)((int)&unaff_s4->d + 1);
              } while( true );
            }
            iVar3 = 0;
            if (iVar6 != 0) goto LAB_00512754;
          }
          local_d8 = local_d8 + 1;
          if (local_d8 == 0x1000) goto LAB_005124a0;
          iVar3 = BN_GENCB_call(param_10,0,local_d8);
          if (iVar3 == 0) goto LAB_00512750;
        } while( true );
      }
      iVar3 = 0;
      if (iVar6 != 0) goto LAB_00512754;
LAB_005124a0:
      local_dc = local_dc + 1;
    } while( true );
  }
  iVar3 = 0;
LAB_00511f80:
  do {
    if (local_2c == *(int *)puVar2) {
      return iVar3;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0051294c:
    iVar3 = BN_GENCB_call(param_10,3,1);
    pBVar5 = unaff_s2;
    unaff_s3 = pBVar11;
    if (iVar3 == 0) {
LAB_00512750:
      iVar3 = 0;
    }
    else {
      if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0xc));
      }
      if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x10));
      }
      if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(param_1 + 0x14));
      }
      pBVar10 = BN_dup(unaff_s2);
      *(BIGNUM **)(param_1 + 0xc) = pBVar10;
      pBVar10 = BN_dup(unaff_s1);
      *(BIGNUM **)(param_1 + 0x10) = pBVar10;
      pBVar11 = BN_dup(pBVar11);
      *(BIGNUM **)(param_1 + 0x14) = pBVar11;
      if (*(int *)(param_1 + 0xc) == 0) goto LAB_00512750;
      iVar3 = 0;
      if ((*(int *)(param_1 + 0x10) != 0) && (pBVar11 != (BIGNUM *)0x0)) {
        if (param_8 != (int *)0x0) {
          *param_8 = local_d8;
        }
        if (param_9 != (BIGNUM **)0x0) {
          *param_9 = unaff_s4;
        }
        if (param_7 == 0) {
          iVar3 = 1;
        }
        else {
          iVar3 = 1;
          (*(code *)PTR_memcpy_006a9aec)(param_7,local_e8,count);
        }
      }
    }
LAB_00512754:
    BN_CTX_end((BN_CTX *)local_ec);
    BN_CTX_free((BN_CTX *)local_ec);
    unaff_s1 = local_ec;
    pBVar10 = pBVar5;
LAB_00512778:
    BN_MONT_CTX_free(local_f0);
    param_1 = iVar3;
    unaff_s2 = pBVar10;
    pBVar11 = unaff_s3;
  } while( true );
}

