
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uchar *****pppppuVar8;
  uchar *****pppppuVar9;
  undefined4 uVar10;
  stack_st_OPENSSL_BLOCK *unaff_s0;
  int **unaff_s1;
  uchar *****unaff_s2;
  uchar *****unaff_s3;
  int unaff_s4;
  uchar *****unaff_s5;
  int **unaff_s7;
  code *pcVar11;
  code *pcVar12;
  int **ppiVar13;
  uchar ****ppppuStack_b0;
  int iStack_ac;
  uint uStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  int iStack_98;
  uchar ****ppppuStack_94;
  int iStack_84;
  stack_st_OPENSSL_BLOCK *psStack_7c;
  int **ppiStack_78;
  uchar *****pppppuStack_74;
  uchar *****pppppuStack_70;
  int iStack_6c;
  uchar *****pppppuStack_68;
  undefined *puStack_64;
  int **ppiStack_60;
  code *pcStack_5c;
  int local_48;
  int iStack_44;
  undefined *local_40;
  uchar *****local_38;
  int local_34;
  uchar *****local_30;
  int *local_2c;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  pppppuVar8 = (uchar *****)pp;
  pppppuVar9 = (uchar *****)i2d;
  pcVar11 = (code *)ex_tag;
  psStack_7c = unaff_s0;
  iStack_6c = unaff_s4;
  if (a == (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_0062a794:
    pp = (uchar **)unaff_s5;
    i2d = (undefined1 *)unaff_s1;
    iVar3 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)();
    unaff_s2 = (uchar *****)(iVar3 + -1);
    unaff_s3 = (uchar *****)0x0;
    pppppuVar8 = unaff_s2;
    if (-1 < (int)unaff_s2) {
      do {
        unaff_s2 = (uchar *****)((int)pppppuVar8 + -1);
        uVar4 = (**(code **)(local_40 + -0x7fbc))(a,pppppuVar8);
        iVar3 = (*(code *)i2d)(uVar4,0);
        unaff_s3 = (uchar *****)((int)unaff_s3 + iVar3);
        pppppuVar8 = unaff_s2;
      } while (unaff_s2 != (uchar *****)0xffffffff);
    }
    pppppuVar8 = unaff_s3;
    pppppuVar9 = (uchar *****)ex_tag;
    iVar3 = (**(code **)(local_40 + -0x69e4))(1);
    psStack_7c = a;
    iStack_6c = iVar3;
    unaff_s7 = (int **)ex_tag;
    if (pp != (uchar **)0x0) {
      local_30 = (uchar *****)*pp;
      unaff_s2 = (uchar *****)&local_30;
      pppppuVar8 = (uchar *****)0x1;
      local_48 = ex_class;
      pppppuVar9 = unaff_s3;
      pcVar11 = (code *)ex_tag;
      (**(code **)(local_40 + -0x69e0))(unaff_s2);
      if ((is_set != 0) && (iVar5 = (**(code **)(local_40 + -0x7fb4))(a), 1 < iVar5)) {
        local_38 = local_30;
        iVar5 = (**(code **)(local_40 + -0x7fb4))(a);
        local_34 = 0x680000;
        unaff_s7 = (int **)(**(code **)(local_40 + -0x7dd8))(iVar5 << 3,"a_set.c",0x7b);
        if (unaff_s7 == (int **)0x0) {
          pcVar12 = *(code **)(local_40 + -0x6eb0);
          local_48 = 0x7e;
          iVar3 = local_34;
        }
        else {
          ppiVar13 = unaff_s7;
          for (unaff_s3 = (uchar *****)0x0; iVar5 = (**(code **)(local_40 + -0x7fb4))(a),
              (int)unaff_s3 < iVar5; unaff_s3 = (uchar *****)((int)unaff_s3 + 1)) {
            pcVar11 = *(code **)(local_40 + -0x7fbc);
            *ppiVar13 = (int *)local_30;
            uVar4 = (*pcVar11)(a,unaff_s3);
            (*(code *)i2d)(uVar4,unaff_s2);
            ppiVar13[1] = (int *)((int)local_30 - (int)*ppiVar13);
            ppiVar13 = ppiVar13 + 2;
          }
          pcVar11 = *(code **)(local_40 + -0x7fb4);
          *pp = (uchar *)local_30;
          unaff_s2 = (uchar *****)((int)local_30 - (int)local_38);
          uVar4 = (*pcVar11)(a);
          pcVar11 = SetBlobCmp;
          (**(code **)(local_40 + -0x544c))(unaff_s7,uVar4,8);
          pp = (uchar **)(**(code **)(local_40 + -0x7dd8))(unaff_s2,local_34 + -0x3318,0x90);
          if ((uchar *****)pp != (uchar *****)0x0) {
            i2d = (undefined1 *)(unaff_s7 + 1);
            local_30 = (uchar *****)pp;
            for (unaff_s3 = (uchar *****)0x0; iVar5 = (**(code **)(local_40 + -0x7fb4))(a),
                (int)unaff_s3 < iVar5; unaff_s3 = (uchar *****)((int)unaff_s3 + 1)) {
              (**(code **)(local_40 + -0x52ec))(local_30,*(int **)((int)i2d + -4),*(int **)i2d);
              local_30 = (uchar *****)((int)local_30 + (int)*(int **)i2d);
              i2d = (undefined1 *)((int)i2d + 8);
            }
            pppppuVar8 = (uchar *****)pp;
            pppppuVar9 = unaff_s2;
            (**(code **)(local_40 + -0x52ec))(local_38);
            (**(code **)(local_40 + -0x7f58))(pp);
            (**(code **)(local_40 + -0x7f58))(unaff_s7);
            goto LAB_0062a730;
          }
          pcVar12 = *(code **)(local_40 + -0x6eb0);
          local_48 = 0x92;
          iVar3 = 0x680000;
        }
        pcVar11 = (code *)(iVar3 + -0x3318);
        pppppuVar9 = (uchar *****)&DAT_00000041;
        pppppuVar8 = (uchar *****)&DAT_000000bc;
        (*pcVar12)(0xd);
        unaff_s1 = (int **)i2d;
        unaff_s5 = (uchar *****)pp;
        goto LAB_0062a794;
      }
      for (unaff_s3 = (uchar *****)0x0; iVar5 = (**(code **)(local_40 + -0x7fb4))(a),
          (int)unaff_s3 < iVar5; unaff_s3 = (uchar *****)((int)unaff_s3 + 1)) {
        uVar4 = (**(code **)(local_40 + -0x7fbc))(a,unaff_s3);
        pppppuVar8 = unaff_s2;
        (*(code *)i2d)(uVar4);
      }
      *pp = (uchar *)local_30;
    }
  }
LAB_0062a730:
  if (local_2c == *(int **)puStack_64) {
    return iVar3;
  }
  pcStack_5c = d2i_ASN1_SET;
  piVar7 = local_2c;
  (**(code **)(local_40 + -0x5328))();
  iVar3 = local_48;
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppiStack_78 = (int **)i2d;
  pppppuStack_74 = unaff_s2;
  pppppuStack_70 = unaff_s3;
  pppppuStack_68 = (uchar *****)pp;
  ppiStack_60 = unaff_s7;
  if (((piVar7 == (int *)0x0) || (iVar5 = *piVar7, iVar5 == 0)) &&
     (iVar5 = (*(code *)PTR_sk_new_null_006a80a4)(), iVar5 == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,0x41,"a_set.c",0xb3);
    iVar6 = 0;
    goto LAB_0062aa98;
  }
  ppppuStack_b0 = *pppppuVar8;
  if (pppppuVar9 == (uchar *****)0x0) {
    ppppuStack_94 = (uchar ****)0x0;
  }
  else {
    ppppuStack_94 = (uchar ****)((int)ppppuStack_b0 + (int)pppppuVar9);
  }
  uStack_a4 = (*(code *)PTR_ASN1_get_object_006a9514)
                        (&ppppuStack_b0,&iStack_98,&iStack_a0,&puStack_9c,
                         (int)ppppuStack_94 - (int)ppppuStack_b0);
  if ((uStack_a4 & 0x80) == 0) {
    if (puStack_9c == local_40) {
      if (iStack_a0 == iStack_44) {
        if ((uchar ****)((int)ppppuStack_b0 + iStack_98) <= ppppuStack_94) {
          ppppuStack_94 = (uchar ****)((int)ppppuStack_b0 + iStack_98);
          if (uStack_a4 == 0x21) {
            ppppuStack_94 = (uchar ****)((int)*pppppuVar8 + (int)pppppuVar9);
            iStack_98 = (int)ppppuStack_94 - (int)ppppuStack_b0;
          }
          do {
            if (ppppuStack_94 <= ppppuStack_b0) {
LAB_0062ac1c:
              if (piVar7 != (int *)0x0) {
                *piVar7 = iVar5;
              }
              *pppppuVar8 = ppppuStack_b0;
              iVar6 = iVar5;
              goto LAB_0062aa98;
            }
            if ((uStack_a4 & 1) == 0) {
              bVar1 = iStack_98 < 1;
            }
            else {
              iStack_ac = (*(code *)PTR_ASN1_const_check_infinite_end_006a951c)
                                    (&ppppuStack_b0,iStack_98);
              bVar1 = iStack_ac != 0;
            }
            if (bVar1) goto LAB_0062ac1c;
            iVar6 = (*pcVar11)(0,&ppppuStack_b0,iStack_98);
            if (iVar6 == 0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,0x71,"a_set.c",0xdd);
              (*(code *)PTR_asn1_add_error_006a9508)
                        (*pppppuVar8,(int)ppppuStack_b0 - (int)*pppppuVar8);
              break;
            }
            iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar5,iVar6);
          } while (iVar6 != 0);
          goto LAB_0062aa68;
        }
        uVar10 = 0x88;
        uVar4 = 0xcb;
      }
      else {
        uVar10 = 0x68;
        uVar4 = 0xc6;
      }
    }
    else {
      uVar10 = 0x65;
      uVar4 = 0xc1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x94,uVar10,"a_set.c",uVar4);
  }
LAB_0062aa68:
  if ((piVar7 == (int *)0x0) || (iVar6 = 0, iVar5 != *piVar7)) {
    if (iVar3 == 0) {
      (*(code *)PTR_sk_free_006a7f80)(iVar5);
      iVar6 = 0;
    }
    else {
      (*(code *)PTR_sk_pop_free_006a8158)(iVar5,iVar3);
      iVar6 = 0;
    }
  }
LAB_0062aa98:
  if (iStack_84 == *(int *)puVar2) {
    return iVar6;
  }
  iVar3 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar3 + 0x24) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0062acb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_BIO_callback_ctrl_006a9548)();
  return iVar3;
}

