
uint crl_cb(int param_1,ASN1_ENUMERATED *param_2,ASN1_INTEGER *param_3,int param_4)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  EVP_MD *pEVar4;
  undefined4 *puVar5;
  ASN1_ENUMERATED *pAVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  ASN1_INTEGER **ppAVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  byte *pbVar15;
  ASN1_INTEGER *pAVar16;
  ASN1_ENUMERATED *unaff_s0;
  ASN1_INTEGER *pAVar17;
  ASN1_ENUMERATED *unaff_s1;
  int unaff_s3;
  undefined4 uVar18;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  ASN1_ENUMERATED *unaff_s7;
  code *pcVar19;
  ASN1_INTEGER *unaff_s8;
  ASN1_INTEGER AStack_8c;
  int iStack_74;
  ASN1_ENUMERATED *pAStack_70;
  ASN1_ENUMERATED *pAStack_6c;
  int *piStack_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined *puStack_58;
  ASN1_ENUMERATED *pAStack_54;
  ASN1_INTEGER *pAStack_50;
  code *pcStack_4c;
  undefined *local_38;
  ASN1_ENUMERATED *local_30;
  int *local_2c;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  piStack_68 = (int *)param_2->length;
  local_38 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (param_1 == 3) {
    if ((*(code **)(piStack_68[0x11] + 8) == (code *)0x0) ||
       (uVar3 = (**(code **)(piStack_68[0x11] + 8))(piStack_68), uVar3 != 0)) {
      if (piStack_68[5] != 0) {
        (**(code **)(local_38 + -0x60c0))();
      }
      if (piStack_68[6] != 0) {
        (**(code **)(local_38 + -0x6090))();
      }
      ASN1_INTEGER_free((ASN1_INTEGER *)piStack_68[9]);
      ASN1_INTEGER_free((ASN1_INTEGER *)piStack_68[10]);
      param_2 = *(ASN1_ENUMERATED **)(local_38 + -0x7a40);
      (**(code **)(local_38 + -0x7d88))(piStack_68[0x10]);
      uVar3 = 1;
    }
    goto LAB_00557948;
  }
  uVar3 = 1;
  if (param_1 == 5) {
    pEVar4 = EVP_sha1();
    (**(code **)(local_38 + -0x7804))(piStack_68,pEVar4,piStack_68 + 0xb,0);
    puVar5 = (undefined4 *)(**(code **)(local_38 + -0x7818))(piStack_68,0x302,0,0);
    piStack_68[6] = (int)puVar5;
    if (puVar5 != (undefined4 *)0x0) {
      uVar14 = piStack_68[7];
      iVar8 = puVar5[1];
      uVar3 = uVar14 | 1;
      piStack_68[7] = uVar3;
      if (iVar8 < 1) {
        iVar8 = 2;
        iVar9 = 1;
      }
      else {
        uVar3 = uVar14 | 5;
        iVar8 = 3;
        iVar9 = 2;
        piStack_68[7] = uVar3;
      }
      if ((int)puVar5[2] < 1) {
        iVar8 = iVar9;
        if (0 < (int)puVar5[5]) goto LAB_00557a4c;
        iVar8 = puVar5[4];
      }
      else {
        iVar11 = puVar5[5];
        uVar3 = uVar3 | 8;
        piStack_68[7] = uVar3;
        if (0 < iVar11) {
LAB_00557a4c:
          uVar3 = uVar3 | 0x10;
          piStack_68[7] = uVar3;
          iVar9 = iVar8;
        }
        if (iVar9 != 1) {
          uVar3 = uVar3 | 2;
          piStack_68[7] = uVar3;
        }
        iVar8 = puVar5[4];
      }
      if (0 < iVar8) {
        uVar3 = uVar3 | 0x20;
        piStack_68[7] = uVar3;
      }
      piVar13 = (int *)puVar5[3];
      if (piVar13 != (int *)0x0) {
        iVar8 = *piVar13;
        piStack_68[7] = uVar3 | 0x40;
        if (iVar8 < 1) {
          uVar3 = piStack_68[8];
        }
        else {
          pbVar15 = (byte *)piVar13[2];
          bVar1 = *pbVar15;
          uVar3 = (uint)bVar1;
          piStack_68[8] = uVar3;
          if (iVar8 != 1) {
            uVar3 = (uint)CONCAT11(pbVar15[1],bVar1);
          }
        }
        piStack_68[8] = uVar3 & 0x807f;
      }
      (**(code **)(local_38 + -0x609c))(*puVar5,*(undefined4 *)(*piStack_68 + 8));
    }
    iVar8 = (**(code **)(local_38 + -0x7818))(piStack_68,0x5a,0,0);
    piStack_68[5] = iVar8;
    iVar8 = (**(code **)(local_38 + -0x7818))(piStack_68,0x58,0,0);
    param_4 = 0;
    param_3 = (ASN1_INTEGER *)0x0;
    param_2 = (ASN1_ENUMERATED *)&DAT_0000008c;
    piStack_68[9] = iVar8;
    iVar8 = (**(code **)(local_38 + -0x7818))(piStack_68);
    piStack_68[10] = iVar8;
    if ((iVar8 != 0) && (piStack_68[9] == 0)) {
      piStack_68[4] = piStack_68[4] | 0x80;
    }
    uVar18 = *(undefined4 *)(*piStack_68 + 0x18);
    pAVar6 = (ASN1_ENUMERATED *)0x0;
    do {
      while( true ) {
        unaff_s0 = pAVar6;
        iVar8 = (**(code **)(local_38 + -0x7fb4))(uVar18);
        if (iVar8 <= (int)unaff_s0) goto LAB_00557be8;
        param_2 = unaff_s0;
        unaff_s1 = (ASN1_ENUMERATED *)(**(code **)(local_38 + -0x7fbc))(uVar18);
        iVar8 = (**(code **)(local_38 + -0x7cb4))(unaff_s1->length);
        if (iVar8 == 0x359) break;
        if (0 < unaff_s1->type) goto LAB_00557bcc;
        pAVar6 = (ASN1_ENUMERATED *)((int)&unaff_s0->length + 1);
      }
      piStack_68[4] = piStack_68[4] | 0x1000;
      pAVar6 = (ASN1_ENUMERATED *)((int)&unaff_s0->length + 1);
    } while (unaff_s1->type < 1);
LAB_00557bcc:
    if ((iVar8 != 0x302) && (iVar8 != 0x8c)) {
      piStack_68[4] = piStack_68[4] | 0x200;
    }
LAB_00557be8:
    unaff_s3 = 0;
    unaff_s8 = (ASN1_INTEGER *)&local_30;
    unaff_s5 = 0xffffffff;
    unaff_s4 = *(undefined4 *)(*piStack_68 + 0x14);
    iVar8 = (**(code **)(local_38 + -0x7fb4))(unaff_s4);
    unaff_s7 = (ASN1_ENUMERATED *)0x0;
    if (0 < iVar8) {
      do {
        unaff_s0 = (ASN1_ENUMERATED *)(**(code **)(local_38 + -0x7fbc))(unaff_s4,unaff_s3);
        param_4 = 0;
        param_2 = (ASN1_ENUMERATED *)0x303;
        param_3 = unaff_s8;
        pAVar6 = (ASN1_ENUMERATED *)(**(code **)(local_38 + -0x6098))(unaff_s0);
        if (pAVar6 != (ASN1_ENUMERATED *)0x0) {
          iVar8 = piStack_68[0x10];
          unaff_s1 = pAVar6;
          if (iVar8 == 0) {
            iVar8 = (**(code **)(local_38 + -0x7e3c))();
            piStack_68[0x10] = iVar8;
            if (iVar8 != 0) goto LAB_00557c60;
          }
          else {
LAB_00557c60:
            param_2 = pAVar6;
            iVar8 = (**(code **)(local_38 + -0x7e38))(iVar8);
            if (iVar8 != 0) goto LAB_00557c74;
          }
          uVar3 = 0;
          goto LAB_00557948;
        }
        unaff_s1 = unaff_s7;
        if (local_30 != (ASN1_ENUMERATED *)0xffffffff) {
LAB_00557e84:
          unaff_s1 = pAVar6;
          piStack_68[4] = piStack_68[4] | 0x80;
          break;
        }
LAB_00557c74:
        pcVar19 = *(code **)(local_38 + -0x6098);
        param_4 = 0;
        param_2 = (ASN1_ENUMERATED *)0x8d;
        unaff_s0->flags = (long)unaff_s1;
        param_3 = unaff_s8;
        unaff_s7 = (ASN1_ENUMERATED *)(*pcVar19)(unaff_s0);
        if (unaff_s7 == (ASN1_ENUMERATED *)0x0) {
          pAVar6 = unaff_s1;
          if (local_30 != (ASN1_ENUMERATED *)0xffffffff) goto LAB_00557e84;
          unaff_s0[1].length = -1;
        }
        else {
          lVar7 = ASN1_ENUMERATED_get(unaff_s7);
          unaff_s0[1].length = lVar7;
          ASN1_ENUMERATED_free(unaff_s7);
        }
        unaff_s0 = (ASN1_ENUMERATED *)unaff_s0->data;
        local_30 = (ASN1_ENUMERATED *)0x0;
        while (iVar8 = (**(code **)(local_38 + -0x7fb4))(unaff_s0), param_2 = local_30,
              (int)local_30 < iVar8) {
          puVar5 = (undefined4 *)(**(code **)(local_38 + -0x7fbc))(unaff_s0);
          if ((0 < (int)puVar5[1]) &&
             (iVar8 = (**(code **)(local_38 + -0x7cb4))(*puVar5), iVar8 != 0x303)) {
            piStack_68[4] = piStack_68[4] | 0x200;
            break;
          }
          local_30 = (ASN1_ENUMERATED *)((int)&local_30->length + 1);
        }
        unaff_s3 = unaff_s3 + 1;
        iVar8 = (**(code **)(local_38 + -0x7fb4))(unaff_s4);
        unaff_s7 = unaff_s1;
      } while (unaff_s3 < iVar8);
    }
    if (*(code **)(piStack_68[0x11] + 4) != (code *)0x0) {
      iVar8 = (**(code **)(piStack_68[0x11] + 4))(piStack_68);
      uVar3 = (uint)(iVar8 != 0);
      goto LAB_00557948;
    }
  }
  else if (param_1 == 1) {
    piStack_68[6] = 0;
    piStack_68[5] = 0;
    piStack_68[4] = 0;
    piStack_68[8] = 0x807f;
    piStack_68[7] = 0;
    piStack_68[0x12] = 0;
    piStack_68[0x10] = 0;
    piStack_68[9] = 0;
    piStack_68[10] = 0;
    piStack_68[0x11] = (int)default_crl_method;
    goto LAB_00557948;
  }
  uVar3 = 1;
LAB_00557948:
  if (local_2c == *(int **)puStack_58) {
    return uVar3;
  }
  pcStack_4c = def_crl_lookup;
  piVar13 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  AStack_8c.length = (int)param_3;
  pAStack_70 = unaff_s0;
  pAStack_6c = unaff_s1;
  iStack_64 = unaff_s3;
  uStack_60 = unaff_s4;
  uStack_5c = unaff_s5;
  pAStack_54 = unaff_s7;
  pAStack_50 = unaff_s8;
  iVar8 = (*(code *)PTR_sk_is_sorted_006a9e54)(*(undefined4 *)(*piVar13 + 0x14));
  if (iVar8 == 0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,6,"x_crl.c",0x1c7);
    (*(code *)PTR_sk_sort_006a94d8)(*(undefined4 *)(*piVar13 + 0x14));
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,6,"x_crl.c",0x1c9);
  }
  pAVar16 = &AStack_8c;
  iVar8 = (*(code *)PTR_sk_find_006a906c)(*(undefined4 *)(*piVar13 + 0x14));
  if ((-1 < iVar8) &&
     (iVar9 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar13 + 0x14)), iVar8 < iVar9)) {
    while( true ) {
      ppAVar10 = (ASN1_INTEGER **)
                 (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(*piVar13 + 0x14),iVar8);
      pAVar16 = param_3;
      iVar9 = ASN1_INTEGER_cmp(*ppAVar10,param_3);
      if (iVar9 != 0) break;
      if (ppAVar10[3] == (ASN1_INTEGER *)0x0) {
        if (param_4 != 0) {
          pAVar16 = *(ASN1_INTEGER **)(*piVar13 + 8);
          iVar9 = (*(code *)PTR_X509_NAME_cmp_006a918c)(param_4);
          if (iVar9 != 0) goto LAB_00557ff8;
        }
LAB_00558070:
        if (param_2 != (ASN1_ENUMERATED *)0x0) {
          param_2->length = (int)ppAVar10;
        }
        uVar3 = 2;
        if (ppAVar10[4] != (ASN1_INTEGER *)&DAT_00000008) {
          uVar3 = 1;
        }
        goto LAB_00558018;
      }
      iVar9 = param_4;
      if (param_4 == 0) {
        iVar9 = *(int *)(*piVar13 + 8);
      }
      pAVar17 = (ASN1_INTEGER *)0x0;
      iVar11 = (*(code *)PTR_sk_num_006a7f2c)();
      if (0 < iVar11) {
        do {
          pAVar16 = pAVar17;
          piVar12 = (int *)(*(code *)PTR_sk_value_006a7f24)(ppAVar10[3]);
          if (*piVar12 == 4) {
            pAVar16 = (ASN1_INTEGER *)piVar12[1];
            iVar11 = (*(code *)PTR_X509_NAME_cmp_006a918c)(iVar9);
            if (iVar11 == 0) goto LAB_00558070;
          }
          pAVar17 = (ASN1_INTEGER *)((int)&pAVar17->length + 1);
          iVar11 = (*(code *)PTR_sk_num_006a7f2c)(ppAVar10[3]);
        } while ((int)pAVar17 < iVar11);
      }
LAB_00557ff8:
      iVar8 = iVar8 + 1;
      iVar9 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*piVar13 + 0x14));
      if (iVar9 <= iVar8) break;
    }
  }
  uVar3 = 0;
LAB_00558018:
  if (iStack_74 == *(int *)puVar2) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar13 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar3 = (uint)X509_REVOKED_it[0];
  if (X509_REVOKED_it._16_4_ == 0) {
    if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar3])();
      return uVar3;
    }
  }
  else if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar3])();
    return uVar3;
  }
  if (piVar13 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(uint *)(*piVar13 + pAVar16->type);
}

