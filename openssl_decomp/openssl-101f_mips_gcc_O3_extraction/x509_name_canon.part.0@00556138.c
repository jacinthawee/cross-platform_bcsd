
undefined * x509_name_canon_part_0(undefined4 *param_1,code *param_2,undefined1 *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  ulong uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  undefined *puVar10;
  byte *pbVar11;
  ASN1_VALUE *pAVar12;
  int **ppiVar13;
  byte *pbVar14;
  code *pcVar15;
  uchar *******pppppppuVar16;
  ASN1_STRING *in;
  byte *pbVar17;
  int *piVar18;
  undefined1 *unaff_s1;
  uchar *******pppppppuVar19;
  undefined1 *unaff_s2;
  ASN1_STRING *unaff_s3;
  ASN1_VALUE **unaff_s4;
  byte *unaff_s5;
  byte *unaff_s6;
  int unaff_s7;
  uchar *******pppppppuStack_fc;
  ASN1_VALUE *pAStack_f8;
  int iStack_f4;
  undefined *puStack_ec;
  undefined4 *puStack_e8;
  ASN1_VALUE **ppAStack_e4;
  undefined4 *puStack_e0;
  ASN1_VALUE **ppAStack_dc;
  int *piStack_d8;
  undefined *puStack_d4;
  int iStack_d0;
  code *pcStack_cc;
  int in_stack_ffffff48;
  int iStack_b4;
  ASN1_TLC *pAStack_ac;
  ASN1_VALUE *pAStack_a4;
  uchar *puStack_a0;
  int **ppiStack_9c;
  undefined *puStack_98;
  undefined4 *puStack_94;
  ASN1_VALUE **ppAStack_90;
  ASN1_STRING *pAStack_8c;
  ASN1_VALUE **ppAStack_88;
  byte *pbStack_84;
  byte *pbStack_80;
  code *pcStack_7c;
  int local_50;
  int local_4c;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  undefined4 *local_2c;
  
  puVar10 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar2 == 0) {
    puStack_ec = (undefined *)0x0;
  }
  else {
    unaff_s2 = (undefined1 *)0x0;
    local_4c = 0;
    local_50 = -1;
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(*param_1);
    if (0 < iVar3) {
      do {
        puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(*param_1,unaff_s2);
        if (puVar4[2] != local_50) {
          local_4c = (*(code *)PTR_sk_new_null_006a80a4)();
          if ((local_4c == 0) ||
             (iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar2,local_4c), iVar3 == 0))
          goto LAB_00556654;
          local_50 = puVar4[2];
        }
        unaff_s1 = ASN1_item_new((ASN1_ITEM *)X509_NAME_ENTRY_it);
        uVar5 = (*(code *)PTR_OBJ_dup_006a95b4)(*puVar4);
        in = (ASN1_STRING *)puVar4[1];
        unaff_s3 = *(ASN1_STRING **)((int)unaff_s1 + 4);
        *(undefined4 *)unaff_s1 = uVar5;
        uVar6 = ASN1_tag2bit(in->type);
        if ((uVar6 & 0x2956) != 0) {
          unaff_s3->type = 0xc;
          unaff_s7 = ASN1_STRING_to_UTF8(&unaff_s3->data,in);
          unaff_s3->length = unaff_s7;
          if (unaff_s7 != -1) {
            pbVar17 = unaff_s3->data;
            if (unaff_s7 < 1) {
LAB_0055630c:
              unaff_s3->length = 0;
            }
            else {
              bVar1 = *pbVar17;
              iVar3 = unaff_s7;
              pbVar11 = pbVar17;
              if (-1 < (char)bVar1) {
                piVar18 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
                do {
                  unaff_s5 = (byte *)(uint)bVar1;
                  unaff_s7 = iVar3 + -1;
                  if ((*(ushort *)(*piVar18 + (int)unaff_s5 * 2) & 0x20) == 0) break;
                  pbVar11 = pbVar11 + 1;
                  if (unaff_s7 == 0) goto LAB_0055630c;
                  bVar1 = *pbVar11;
                  iVar3 = unaff_s7;
                } while (-1 < (char)bVar1);
              }
              pbVar14 = pbVar11 + iVar3 + -1;
              bVar1 = *pbVar14;
              if (-1 < (char)bVar1) {
                piVar18 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
                do {
                  unaff_s5 = (byte *)(uint)bVar1;
                  unaff_s7 = iVar3 + -1;
                  if ((*(ushort *)(*piVar18 + (int)unaff_s5 * 2) & 0x20) == 0) break;
                  pbVar14 = pbVar14 + -1;
                  if (unaff_s7 == 0) goto LAB_0055630c;
                  bVar1 = *pbVar14;
                  iVar3 = unaff_s7;
                } while (-1 < (char)bVar1);
              }
              pbVar17 = (byte *)0x0;
              unaff_s5 = pbVar17 + 1;
              do {
                unaff_s6 = unaff_s5;
                bVar1 = *pbVar11;
                unaff_s4 = (ASN1_VALUE **)(uint)bVar1;
                if ((char)bVar1 < '\0') {
                  unaff_s6[-1] = bVar1;
                  pbVar11 = pbVar11 + 1;
                  pbVar17 = pbVar17 + 1;
                }
                else {
                  piVar18 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
                  if ((*(ushort *)(*piVar18 + (int)unaff_s4 * 2) & 0x20) == 0) {
                    pbVar11 = pbVar11 + 1;
                    pbVar17 = pbVar17 + 1;
                    piVar18 = (int *)(*(code *)PTR___ctype_tolower_loc_006aaa50)();
                    unaff_s6[-1] = (byte)*(undefined4 *)(*piVar18 + (int)unaff_s4 * 4);
                  }
                  else {
                    iVar7 = (int)pbVar17 - (int)pbVar11;
                    unaff_s6[-1] = 0x20;
                    do {
                      pbVar11 = pbVar11 + 1;
                      pbVar17 = pbVar11 + iVar7;
                      if ((char)*pbVar11 < '\0') break;
                    } while ((*(ushort *)(*piVar18 + (uint)*pbVar11 * 2) & 0x20) != 0);
                  }
                }
                unaff_s5 = unaff_s6 + 1;
              } while ((int)pbVar17 < iVar3);
              unaff_s3->length = (int)unaff_s6 - (int)unaff_s3->data;
              unaff_s7 = iVar3;
            }
            goto LAB_00556314;
          }
LAB_00556298:
          puStack_ec = (undefined *)0x0;
          ASN1_item_free((ASN1_VALUE *)unaff_s1,(ASN1_ITEM *)X509_NAME_ENTRY_it);
          goto LAB_005562b0;
        }
        iVar3 = ASN1_STRING_copy(unaff_s3,in);
        if (iVar3 == 0) goto LAB_00556298;
LAB_00556314:
        iVar3 = (*(code *)PTR_sk_push_006a80a8)(local_4c,unaff_s1);
        if (iVar3 == 0) goto LAB_00556298;
        unaff_s2 = (undefined1 *)((int)unaff_s2 + 1);
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(*param_1);
      } while ((int)unaff_s2 < iVar3);
    }
    unaff_s1 = (undefined1 *)0x0;
    unaff_s4 = &local_30;
    unaff_s3 = (ASN1_STRING *)0xffffffff;
    unaff_s2 = X509_NAME_ENTRIES_it;
    for (iVar3 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar2), puVar4 = (undefined4 *)unaff_s1,
        iVar3 < iVar7; iVar3 = iVar3 + 1) {
      local_30 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar3);
      puVar4 = (undefined4 *)
               ASN1_item_ex_i2d(unaff_s4,(uchar **)0x0,(ASN1_ITEM *)X509_NAME_ENTRIES_it,-1,-1);
      if ((int)puVar4 < 0) break;
      unaff_s1 = (undefined1 *)((int)unaff_s1 + (int)puVar4);
    }
    puVar8 = PTR_CRYPTO_malloc_006a8108;
    param_3 = (undefined *)0x16d;
    param_1[4] = puVar4;
    local_34 = (ASN1_VALUE *)(*(code *)puVar8)(puVar4,"x_name.c");
    if (local_34 == (ASN1_VALUE *)0x0) {
LAB_00556654:
      puStack_ec = (undefined *)0x0;
    }
    else {
      param_1[3] = local_34;
      unaff_s4 = &local_34;
      unaff_s3 = (ASN1_STRING *)&local_30;
      unaff_s2 = (undefined1 *)0xffffffff;
      unaff_s1 = X509_NAME_ENTRIES_it;
      for (iVar3 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar2), iVar3 < iVar7;
          iVar3 = iVar3 + 1) {
        local_30 = (ASN1_VALUE *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar3);
        param_3 = unaff_s1;
        iVar7 = ASN1_item_ex_i2d((ASN1_VALUE **)unaff_s3,(uchar **)unaff_s4,
                                 (ASN1_ITEM *)X509_NAME_ENTRIES_it,-1,-1);
        if (iVar7 < 0) break;
      }
      puStack_ec = (undefined *)0x1;
    }
LAB_005562b0:
    param_2 = local_sk_X509_NAME_ENTRY_pop_free;
    (*(code *)PTR_sk_pop_free_006a8158)(iVar2);
  }
  if (local_2c == *(undefined4 **)puVar10) {
    return puStack_ec;
  }
  pcStack_7c = x509_name_ex_i2d;
  puStack_e0 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_d4 = PTR___stack_chk_guard_006aabf0;
  puStack_e0 = (undefined4 *)*puStack_e0;
  ppiStack_9c = *(int ***)PTR___stack_chk_guard_006aabf0;
  pcVar15 = param_2;
  puStack_98 = puStack_ec;
  puStack_94 = (undefined4 *)unaff_s1;
  ppAStack_90 = (ASN1_VALUE **)unaff_s2;
  pAStack_8c = unaff_s3;
  ppAStack_88 = unaff_s4;
  pbStack_84 = unaff_s5;
  pbStack_80 = unaff_s6;
  if (puStack_e0[1] == 0) {
LAB_005566d0:
    puVar4 = (undefined4 *)puStack_e0[2];
    puStack_ec = (undefined *)*puVar4;
joined_r0x005568b0:
    puVar10 = puStack_ec;
    if ((int *)param_2 != (int *)0x0) {
      pcVar15 = (code *)puVar4[1];
      param_3 = puStack_ec;
      (*(code *)PTR_memcpy_006aabf4)(*(int *)param_2);
      iVar2 = *(int *)param_2;
      *(undefined **)param_2 = puStack_ec + iVar2;
      puStack_ec = puStack_ec + iVar2;
    }
  }
  else {
    pAStack_a4 = (ASN1_VALUE *)0x0;
    pAStack_a4 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
    if (pAStack_a4 == (ASN1_VALUE *)0x0) {
      pAVar12 = (ASN1_VALUE *)0x0;
    }
    else {
      unaff_s4 = (ASN1_VALUE **)0xffffffff;
      unaff_s2 = (undefined1 *)0x0;
      for (puStack_ec = (undefined *)0x0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*puStack_e0),
          (int)puStack_ec < iVar2; puStack_ec = puStack_ec + 1) {
        unaff_s1 = (undefined1 *)(*(code *)PTR_sk_value_006a7f24)(*puStack_e0,puStack_ec);
        if (*(ASN1_VALUE ***)((int)unaff_s1 + 8) != unaff_s4) {
          unaff_s2 = (undefined1 *)(*(code *)PTR_sk_new_null_006a80a4)();
          pAVar12 = pAStack_a4;
          if (((ASN1_VALUE **)unaff_s2 == (ASN1_VALUE **)0x0) ||
             (iVar2 = (*(code *)PTR_sk_push_006a80a8)(pAStack_a4,unaff_s2), pAVar12 = pAStack_a4,
             iVar2 == 0)) goto LAB_005568c4;
          unaff_s4 = *(ASN1_VALUE ***)((int)unaff_s1 + 8);
        }
        iVar2 = (*(code *)PTR_sk_push_006a80a8)(unaff_s2,unaff_s1);
        pAVar12 = pAStack_a4;
        if (iVar2 == 0) goto LAB_005568c4;
      }
      unaff_s1 = (undefined1 *)0xffffffff;
      unaff_s4 = (ASN1_VALUE **)(nid_objs + 0x13a4);
      unaff_s2 = (undefined1 *)&pAStack_a4;
      puStack_ec = (undefined *)
                   ASN1_item_ex_i2d((ASN1_VALUE **)unaff_s2,(uchar **)0x0,
                                    (ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
      iVar2 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(puStack_e0[2],puStack_ec);
      pAVar12 = pAStack_a4;
      if (iVar2 != 0) {
        param_3 = X509_NAME_INTERNAL_it;
        puStack_a0 = *(uchar **)(puStack_e0[2] + 4);
        in_stack_ffffff48 = -1;
        ASN1_item_ex_i2d((ASN1_VALUE **)unaff_s2,&puStack_a0,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,
                         -1);
        pcVar15 = local_sk_X509_NAME_ENTRY_free;
        (*(code *)PTR_sk_pop_free_006a8158)(pAStack_a4);
        puStack_e0[1] = 0;
        puVar10 = puStack_ec;
        if (-1 < (int)puStack_ec) {
          if (puStack_e0[3] != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
            puStack_e0[3] = 0;
          }
          iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*puStack_e0);
          if (iVar2 == 0) {
            puVar4 = (undefined4 *)puStack_e0[2];
            puStack_e0[4] = 0;
            puStack_ec = (undefined *)*puVar4;
            goto joined_r0x005568b0;
          }
          puVar10 = (undefined *)x509_name_canon_part_0(puStack_e0);
          if (-1 < (int)puVar10) goto LAB_005566d0;
        }
        goto LAB_00556704;
      }
    }
LAB_005568c4:
    (*(code *)PTR_sk_pop_free_006a8158)(pAVar12,local_sk_X509_NAME_ENTRY_free);
    param_3 = &DAT_00000041;
    in_stack_ffffff48 = 0x122;
    pcVar15 = (code *)0xcb;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xcb,0x41,"x_name.c");
    puVar10 = (undefined *)0xffffffff;
  }
LAB_00556704:
  if (ppiStack_9c == *(int ***)puStack_d4) {
    return puVar10;
  }
  pcStack_cc = x509_name_ex_d2i;
  ppiVar13 = ppiStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  pppppppuVar16 = (uchar *******)&pppppppuStack_fc;
  pppppppuVar19 = *(uchar ********)pcVar15;
  iStack_f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_f8 = (ASN1_VALUE *)0x0;
  pppppppuStack_fc = pppppppuVar19;
  puStack_e8 = (undefined4 *)unaff_s1;
  ppAStack_e4 = (ASN1_VALUE **)unaff_s2;
  ppAStack_dc = unaff_s4;
  piStack_d8 = (int *)param_2;
  iStack_d0 = unaff_s7;
  puVar8 = (undefined *)
           ASN1_item_ex_d2i(&pAStack_f8,(uchar **)pppppppuVar16,(long)param_3,
                            (ASN1_ITEM *)X509_NAME_INTERNAL_it,in_stack_ffffff48,iStack_b4,-0x20,
                            pAStack_ac);
  if ((int)puVar8 < 1) goto LAB_00556ae4;
  piVar18 = *ppiVar13;
  if (piVar18 != (int *)0x0) {
    (*(code *)PTR_BUF_MEM_free_006a8594)(piVar18[2]);
    (*(code *)PTR_sk_pop_free_006a8158)(*piVar18,X509_NAME_ENTRY_free);
    if (piVar18[3] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar18);
    *ppiVar13 = (int *)0x0;
  }
  piVar18 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"x_name.c",0x87);
  if (piVar18 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xab,0x41,"x_name.c",0x93);
  }
  else {
    iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar18 = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_BUF_MEM_new_006a859c)();
      piVar18[2] = iVar2;
      puVar8 = PTR_BUF_MEM_grow_006a85a0;
      if (iVar2 != 0) {
        piVar18[3] = 0;
        piVar18[4] = 0;
        piVar18[1] = 1;
        iVar2 = (*(code *)puVar8)(iVar2,(int)pppppppuStack_fc - (int)pppppppuVar19);
        if (iVar2 != 0) {
          (*(code *)PTR_memcpy_006aabf4)(*(undefined4 *)(piVar18[2] + 4));
          for (pppppppuVar16 = (uchar *******)0x0;
              iVar2 = (*(code *)PTR_sk_num_006a7f2c)(pAStack_f8), (int)pppppppuVar16 < iVar2;
              pppppppuVar16 = (uchar *******)((int)pppppppuVar16 + 1)) {
            pppppppuVar19 = pppppppuVar16;
            uVar5 = (*(code *)PTR_sk_value_006a7f24)(pAStack_f8);
            for (iVar2 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(uVar5), iVar2 < iVar3;
                iVar2 = iVar2 + 1) {
              pppppppuVar19 = (uchar *******)(*(code *)PTR_sk_value_006a7f24)(uVar5,iVar2);
              puVar8 = PTR_sk_push_006a80a8;
              iVar3 = *piVar18;
              pppppppuVar19[2] = (uchar ******)pppppppuVar16;
              iVar3 = (*(code *)puVar8)(iVar3);
              if (iVar3 == 0) goto LAB_00556aa4;
            }
            (*(code *)PTR_sk_free_006a7f80)(uVar5);
          }
          (*(code *)PTR_sk_free_006a7f80)(pAStack_f8);
          pppppppuVar16 = pppppppuVar19;
          if (piVar18[3] != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
            piVar18[3] = 0;
            pppppppuVar16 = pppppppuVar19;
          }
          iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*piVar18);
          if (iVar2 == 0) {
            puVar8 = (undefined *)0x1;
            piVar18[4] = 0;
          }
          else {
            puVar8 = (undefined *)x509_name_canon_part_0(piVar18);
            if (puVar8 == (undefined *)0x0) goto LAB_00556aa4;
          }
          piVar18[1] = 0;
          *ppiVar13 = piVar18;
          *(uchar ********)pcVar15 = pppppppuStack_fc;
          goto LAB_00556ae4;
        }
LAB_00556aa4:
        ASN1_item_free((ASN1_VALUE *)piVar18,(ASN1_ITEM *)X509_NAME_it);
        goto LAB_00556abc;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xab,0x41,"x_name.c",0x93);
    if (*piVar18 != 0) {
      (*(code *)PTR_sk_free_006a7f80)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar18);
  }
LAB_00556abc:
  pppppppuVar16 = (uchar *******)&DAT_0000009e;
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9e,0x3a,"x_name.c",0xdc);
  puVar8 = (undefined *)0x0;
LAB_00556ae4:
  if (iStack_f4 == *(int *)puVar10) {
    return puVar8;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar18 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar9 = (uint)X509_NAME_ENTRY_it[0];
  if (X509_NAME_ENTRY_it._16_4_ == 0) {
    if (uVar9 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar10 = (undefined *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar9])();
      return puVar10;
    }
  }
  else if (uVar9 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar10 = (undefined *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar9])();
    return puVar10;
  }
  if (piVar18 != *(int **)PTR___stack_chk_guard_006aabf0) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(undefined **)((int)pppppppuVar16[1] + *piVar18);
  }
  return (undefined *)0x0;
}

