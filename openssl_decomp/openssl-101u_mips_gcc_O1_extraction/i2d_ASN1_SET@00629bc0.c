
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *****pppppiVar7;
  int *****pppppiVar8;
  undefined4 uVar9;
  char *pcVar10;
  int *****unaff_s0;
  stack_st_OPENSSL_BLOCK *unaff_s1;
  int *****unaff_s2;
  int unaff_s3;
  int *****unaff_s4;
  uchar **unaff_s6;
  int *****unaff_s7;
  code *pcVar11;
  int iVar12;
  int ****ppppiStack_b0;
  int iStack_ac;
  uint uStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  int iStack_98;
  int ****ppppiStack_94;
  int iStack_84;
  int *****pppppiStack_7c;
  stack_st_OPENSSL_BLOCK *psStack_78;
  int *****pppppiStack_74;
  int iStack_70;
  int *****pppppiStack_6c;
  undefined *puStack_68;
  uchar **ppuStack_64;
  int *****pppppiStack_60;
  code *pcStack_5c;
  int local_48;
  int iStack_44;
  undefined *local_40;
  int *****local_38;
  int local_34;
  int *****local_30;
  int *local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pppppiVar7 = (int *****)pp;
  pppppiVar8 = (int *****)i2d;
  pcVar11 = (code *)ex_tag;
  psStack_78 = unaff_s1;
  if (a == (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_00629de4:
    ex_tag = (int)unaff_s7;
    pp = unaff_s6;
    i2d = (undefined1 *)unaff_s2;
    iVar3 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)();
    iVar3 = iVar3 + -1;
    unaff_s0 = (int *****)0x0;
    psStack_78 = a;
    if (iVar3 < 0) {
LAB_00629d04:
      pppppiVar7 = unaff_s0;
      pppppiVar8 = (int *****)ex_tag;
      unaff_s3 = (**(code **)(local_40 + -0x69fc))(1);
      iVar3 = unaff_s3;
      if ((pp != (uchar **)0x0) && (iVar3 = -1, unaff_s3 != -1)) {
        local_30 = (int *****)*pp;
        unaff_s4 = (int *****)&local_30;
        pppppiVar7 = (int *****)0x1;
        local_48 = ex_class;
        pcVar11 = (code *)ex_tag;
        (**(code **)(local_40 + -0x69f8))(unaff_s4);
        pppppiVar8 = unaff_s0;
        if ((is_set != 0) &&
           (iVar3 = (**(code **)(local_40 + -0x7fb4))(a), pppppiVar8 = unaff_s0, 1 < iVar3)) {
          local_38 = local_30;
          iVar3 = (**(code **)(local_40 + -0x7fb4))(a);
          local_34 = 0x680000;
          unaff_s0 = (int *****)(**(code **)(local_40 + -0x7dd8))(iVar3 << 3,"a_set.c",0x81);
          if (unaff_s0 == (int *****)0x0) {
            pcVar11 = *(code **)(local_40 + -0x6eac);
            pcVar10 = (char *)(local_34 + -0x3ba8);
            local_48 = 0x83;
          }
          else {
            pppppiVar7 = unaff_s0;
            for (iVar3 = 0; iVar12 = (**(code **)(local_40 + -0x7fb4))(a), iVar3 < iVar12;
                iVar3 = iVar3 + 1) {
              pcVar11 = *(code **)(local_40 + -0x7fbc);
              *pppppiVar7 = (int ****)local_30;
              uVar4 = (*pcVar11)(a,iVar3);
              (*(code *)i2d)(uVar4,unaff_s4);
              pppppiVar7[1] = (int ****)((int)local_30 - (int)*pppppiVar7);
              pppppiVar7 = pppppiVar7 + 2;
            }
            pcVar11 = *(code **)(local_40 + -0x7fb4);
            *pp = (uchar *)local_30;
            unaff_s4 = (int *****)((int)local_30 - (int)local_38);
            uVar4 = (*pcVar11)(a);
            pcVar11 = SetBlobCmp;
            (**(code **)(local_40 + -0x5458))(unaff_s0,uVar4,8);
            ex_tag = (**(code **)(local_40 + -0x7dd8))(unaff_s4,local_34 + -0x3ba8,0x95);
            if ((int *****)ex_tag != (int *****)0x0) {
              i2d = (undefined1 *)(unaff_s0 + 1);
              local_30 = (int *****)ex_tag;
              for (pp = (uchar **)0x0; iVar3 = (**(code **)(local_40 + -0x7fb4))(a), (int)pp < iVar3
                  ; pp = (uchar **)((int)pp + 1)) {
                (**(code **)(local_40 + -0x52f4))
                          (local_30,*(int *****)((int)i2d + -4),*(int *****)i2d);
                local_30 = (int *****)((int)local_30 + (int)*(int *****)i2d);
                i2d = (undefined1 *)((int)i2d + 8);
              }
              pppppiVar7 = (int *****)ex_tag;
              pppppiVar8 = unaff_s4;
              (**(code **)(local_40 + -0x52f4))(local_38);
              (**(code **)(local_40 + -0x7f58))(ex_tag);
              (**(code **)(local_40 + -0x7f58))(unaff_s0);
              iVar3 = unaff_s3;
              goto LAB_00629cc8;
            }
            pcVar11 = *(code **)(local_40 + -0x6eac);
            pcVar10 = "a_set.c";
            local_48 = 0x96;
          }
          pppppiVar8 = (int *****)&DAT_00000041;
          pppppiVar7 = (int *****)&DAT_000000bc;
          (*pcVar11)(0xd);
          pcVar11 = (code *)pcVar10;
          unaff_s2 = (int *****)i2d;
          unaff_s6 = pp;
          unaff_s7 = (int *****)ex_tag;
          goto LAB_00629de4;
        }
        for (unaff_s0 = (int *****)0x0; iVar3 = (**(code **)(local_40 + -0x7fb4))(a),
            (int)unaff_s0 < iVar3; unaff_s0 = (int *****)((int)unaff_s0 + 1)) {
          uVar4 = (**(code **)(local_40 + -0x7fbc))(a,unaff_s0);
          pppppiVar7 = unaff_s4;
          (*(code *)i2d)(uVar4);
        }
        *pp = (uchar *)local_30;
        iVar3 = unaff_s3;
      }
    }
    else {
      uVar4 = (**(code **)(local_40 + -0x7fbc))(a,iVar3);
      (*(code *)i2d)(uVar4,0);
      unaff_s0 = (int *****)0x0;
      unaff_s4 = (int *****)0xffffffff;
      unaff_s3 = 0x7fffffff;
      do {
        iVar12 = iVar3 + -1;
        uVar4 = (**(code **)(local_40 + -0x7fbc))(a,iVar3);
        iVar3 = (*(code *)i2d)(uVar4,0);
        unaff_s0 = (int *****)((int)unaff_s0 + iVar3);
        if (iVar12 == -1) goto LAB_00629d04;
        uVar4 = (**(code **)(local_40 + -0x7fbc))(a,iVar12);
        pppppiVar7 = (int *****)0x0;
        iVar5 = (*(code *)i2d)(uVar4);
        iVar3 = iVar12;
      } while (iVar5 <= 0x7fffffff - (int)unaff_s0);
      iVar3 = -1;
    }
  }
LAB_00629cc8:
  if (local_2c == *(int **)puStack_68) {
    return iVar3;
  }
  pcStack_5c = d2i_ASN1_SET;
  piVar6 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  iVar3 = local_48;
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppppiStack_7c = unaff_s0;
  pppppiStack_74 = (int *****)i2d;
  iStack_70 = unaff_s3;
  pppppiStack_6c = unaff_s4;
  ppuStack_64 = pp;
  pppppiStack_60 = (int *****)ex_tag;
  if (((piVar6 == (int *)0x0) || (iVar12 = *piVar6, iVar12 == 0)) &&
     (iVar12 = (*(code *)PTR_sk_new_null_006a6fa4)(), iVar12 == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x94,0x41,"a_set.c",0xb4);
    iVar5 = 0;
    goto LAB_0062a0e8;
  }
  ppppiStack_b0 = *pppppiVar7;
  if (pppppiVar8 == (int *****)0x0) {
    ppppiStack_94 = (int ****)0x0;
  }
  else {
    ppppiStack_94 = (int ****)((int)ppppiStack_b0 + (int)pppppiVar8);
  }
  uStack_a4 = (*(code *)PTR_ASN1_get_object_006a7fb0)
                        (&ppppiStack_b0,&iStack_98,&iStack_a0,&puStack_9c,
                         (int)ppppiStack_94 - (int)ppppiStack_b0);
  if ((uStack_a4 & 0x80) == 0) {
    if (puStack_9c == local_40) {
      if (iStack_a0 == iStack_44) {
        if ((int ****)((int)ppppiStack_b0 + iStack_98) <= ppppiStack_94) {
          ppppiStack_94 = (int ****)((int)ppppiStack_b0 + iStack_98);
          if (uStack_a4 == 0x21) {
            ppppiStack_94 = (int ****)((int)*pppppiVar7 + (int)pppppiVar8);
            iStack_98 = (int)ppppiStack_94 - (int)ppppiStack_b0;
          }
          do {
            if (ppppiStack_94 <= ppppiStack_b0) {
LAB_0062a26c:
              if (piVar6 != (int *)0x0) {
                *piVar6 = iVar12;
              }
              *pppppiVar7 = ppppiStack_b0;
              iVar5 = iVar12;
              goto LAB_0062a0e8;
            }
            if ((uStack_a4 & 1) == 0) {
              bVar1 = iStack_98 < 1;
            }
            else {
              iStack_ac = (*(code *)PTR_ASN1_const_check_infinite_end_006a8400)
                                    (&ppppiStack_b0,iStack_98);
              bVar1 = iStack_ac != 0;
            }
            if (bVar1) goto LAB_0062a26c;
            iVar5 = (*pcVar11)(0,&ppppiStack_b0,iStack_98);
            if (iVar5 == 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x94,0x71,"a_set.c",0xde);
              (*(code *)PTR_asn1_add_error_006a83f0)
                        (*pppppiVar7,(int)ppppiStack_b0 - (int)*pppppiVar7);
              break;
            }
            iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar12,iVar5);
          } while (iVar5 != 0);
          goto LAB_0062a0b8;
        }
        uVar9 = 0x88;
        uVar4 = 0xc9;
      }
      else {
        uVar9 = 0x68;
        uVar4 = 0xc5;
      }
    }
    else {
      uVar9 = 0x65;
      uVar4 = 0xc1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x94,uVar9,"a_set.c",uVar4);
  }
LAB_0062a0b8:
  if ((piVar6 == (int *)0x0) || (iVar5 = 0, iVar12 != *piVar6)) {
    if (iVar3 == 0) {
      (*(code *)PTR_sk_free_006a6e80)(iVar12);
      iVar5 = 0;
    }
    else {
      (*(code *)PTR_sk_pop_free_006a7058)(iVar12,iVar3);
      iVar5 = 0;
    }
  }
LAB_0062a0e8:
  if (iStack_84 == *(int *)puVar2) {
    return iVar5;
  }
  iVar3 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar3 + 0x24) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0062a304. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_BIO_callback_ctrl_006a8428)();
  return iVar3;
}

