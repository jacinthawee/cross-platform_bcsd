
undefined4 do_revoke(int *param_1,int param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  char **ppcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  undefined4 *puVar15;
  char *pcVar16;
  code *pcVar17;
  undefined auStack_a0 [28];
  undefined4 *puStack_84;
  undefined **ppuStack_80;
  undefined **ppuStack_7c;
  undefined *puStack_78;
  int *piStack_74;
  undefined4 uStack_70;
  int *piStack_6c;
  int *piStack_68;
  code *pcStack_64;
  undefined *local_50;
  undefined *local_44;
  int local_40;
  undefined4 local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  undefined *local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  ppuStack_80 = &local_44;
  local_50 = &_gp;
  local_44 = (undefined *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_38 = (int *)0x0;
  local_34 = 0;
  local_30 = (int *)0x0;
  local_2c = *(undefined **)PTR___stack_chk_guard_006aabf0;
  piVar13 = param_4;
  uVar1 = (*(code *)PTR_X509_get_subject_name_006a8000)();
  piVar11 = (int *)0x0;
  local_30 = (int *)(**(code **)(local_50 + -0x7dd0))(uVar1,0);
  uVar1 = (**(code **)(local_50 + -0x7e44))(param_1);
  iVar2 = (**(code **)(local_50 + -0x7dcc))(uVar1,0);
  if (iVar2 == 0) {
    uStack_70 = 0xffffffff;
  }
  else {
    if (*(int *)(iVar2 + 4) == 0) {
      local_38 = (int *)(**(code **)(local_50 + -0x7e04))("00");
    }
    else {
      local_38 = (int *)(**(code **)(local_50 + -0x7dc8))(iVar2);
    }
    (**(code **)(local_50 + -0x7dc4))(iVar2);
    if ((local_30 == (int *)0x0) || (local_38 == (int *)0x0)) {
      uStack_70 = 0xffffffff;
      (**(code **)(local_50 + -0x7fa8))
                (**(undefined4 **)(local_50 + -0x7fa4),"Memory allocation failure\n");
    }
    else {
      ppcVar3 = (char **)(**(code **)(local_50 + -0x7dc0))
                                   (*(undefined4 *)(param_2 + 4),3,ppuStack_80);
      if (ppcVar3 == (char **)0x0) {
        puVar15 = *(undefined4 **)(local_50 + -0x7fa4);
        piVar13 = local_30;
        (**(code **)(local_50 + -0x7fa8))
                  (*puVar15,"Adding Entry with serial number %s to DB for %s\n",local_38);
        local_44 = (undefined *)(**(code **)(local_50 + -0x7dd8))(2,&DAT_00635b2c,0x98c);
        piVar12 = *(int **)(*(int *)(*param_1 + 0x10) + 4);
        local_40 = (**(code **)(local_50 + -0x7dd8))(*piVar12 + 1,&DAT_00635b2c,0x98f);
        (**(code **)(local_50 + -0x52ec))(local_40,piVar12[2],*piVar12);
        piVar11 = (int *)0x996;
        pcVar17 = *(code **)(local_50 + -0x7dd8);
        *(undefined *)(local_40 + *piVar12) = 0;
        local_3c = 0;
        local_34 = (*pcVar17)(8,&DAT_00635b2c);
        if (((local_44 != (undefined *)0x0) && (local_40 != 0)) && (local_34 != 0)) {
          (**(code **)(local_50 + -0x7e7c))(local_34,"unknown",8);
          piVar11 = (int *)0x9a4;
          *local_44 = 0x56;
          pcVar17 = *(code **)(local_50 + -0x7dd8);
          local_44[1] = 0;
          puVar5 = (undefined4 *)(*pcVar17)(0x1c,&DAT_00635b2c);
          if (puVar5 != (undefined4 *)0x0) {
            pcVar17 = *(code **)(local_50 + -0x7db8);
            *puVar5 = local_44;
            local_44 = (undefined *)0x0;
            puVar5[1] = local_40;
            local_40 = 0;
            puVar5[2] = local_3c;
            local_3c = 0;
            puVar5[3] = local_38;
            local_38 = (int *)0x0;
            puVar5[4] = local_34;
            local_34 = 0;
            puVar5[5] = local_30;
            local_30 = (int *)0x0;
            puVar5[6] = 0;
            iVar2 = (*pcVar17)(*(undefined4 *)(param_2 + 4),puVar5);
            if (iVar2 == 0) {
              (**(code **)(local_50 + -0x7fa8))(*puVar15,"failed to update database\n");
              uStack_70 = 0xffffffff;
              piVar11 = *(int **)(*(int *)(param_2 + 4) + 0x10);
              (**(code **)(local_50 + -0x7fa8))(*puVar15,"TXT_DB error number %ld\n");
            }
            else {
              piVar11 = param_3;
              piVar13 = param_4;
              uStack_70 = do_revoke(param_1,param_2);
            }
            goto LAB_0042f5e8;
          }
        }
        uStack_70 = 0xffffffff;
        (**(code **)(local_50 + -0x7fa8))(*puVar15,"Memory allocation failure\n");
      }
      else {
        iVar2 = (**(code **)(local_50 + -0x7dbc))(ppuStack_80,ppcVar3);
        if (iVar2 == 0) {
          param_1 = (int *)0x52;
          if (**ppcVar3 != 'R') {
            puVar15 = *(undefined4 **)(local_50 + -0x7fa4);
            piVar11 = (int *)ppcVar3[3];
            (**(code **)(local_50 + -0x7fa8))(*puVar15,"Revoking Certificate %s.\n");
            pcVar4 = (char *)make_revocation_str(param_3,param_4);
            if (pcVar4 == (char *)0x0) {
              uStack_70 = 0xffffffff;
              (**(code **)(local_50 + -0x7fa8))(*puVar15,"Error in revocation arguments\n");
            }
            else {
              uStack_70 = 1;
              **ppcVar3 = 'R';
              (*ppcVar3)[1] = '\0';
              ppcVar3[2] = pcVar4;
            }
            goto LAB_0042f5e8;
          }
          pcVar17 = *(code **)(local_50 + -0x7fa8);
          pcVar4 = "ERROR:Already revoked, serial number %s\n";
          piVar11 = local_38;
        }
        else {
          pcVar17 = *(code **)(local_50 + -0x7fa8);
          pcVar4 = "ERROR:name does not match %s\n";
          piVar11 = local_30;
        }
        uStack_70 = 0xffffffff;
        (*pcVar17)(**(undefined4 **)(local_50 + -0x7fa4),pcVar4);
      }
    }
  }
LAB_0042f5e8:
  ppuStack_7c = &local_2c;
  puVar9 = local_50;
  do {
    if (*ppuStack_80 != (undefined *)0x0) {
      (**(code **)(puVar9 + -0x7f58))();
      puVar9 = local_50;
    }
    ppuStack_80 = ppuStack_80 + 1;
  } while (ppuStack_80 != ppuStack_7c);
  if (local_2c == *(undefined **)puStack_78) {
    return uStack_70;
  }
  pcStack_64 = old_entry_print;
  puVar7 = local_2c;
  (**(code **)(puVar9 + -0x5328))();
  puVar9 = PTR___stack_chk_guard_006aabf0;
  puStack_84 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  piStack_74 = param_1;
  piStack_6c = param_3;
  piStack_68 = param_4;
  iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)();
  puVar6 = auStack_a0;
  iVar2 = 0x16 - iVar2;
  puVar8 = puVar6;
  if (0 < iVar2) {
    puVar6 = (undefined *)(*(code *)PTR_memset_006aab00)(puVar6,0x20,iVar2);
    puVar8 = puVar6 + iVar2;
  }
  puVar8[1] = 0;
  *puVar8 = 0x3a;
  (*(code *)PTR_BIO_puts_006a8058)(puVar7,puVar6);
  piVar12 = (int *)piVar11[1];
  if (piVar12 == (int *)&DAT_00000013) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"PRINTABLE:\'");
  }
  else if (piVar12 == (int *)&DAT_00000014) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"T61STRING:\'");
  }
  else if (piVar12 == (int *)&DAT_00000016) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"IA5STRING:\'");
  }
  else if (piVar12 == (int *)0x1c) {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"UNIVERSALSTRING:\'");
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"ASN.1 %2d:\'");
  }
  pcVar16 = (char *)piVar11[2];
  pcVar4 = pcVar16 + *piVar11;
  if (0 < *piVar11) {
    do {
      while (piVar12 = (int *)(int)*pcVar16, 0x5e < ((uint)(piVar12 + -8) & 0xff)) {
        if ((int)piVar12 < 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"\\0x%02X");
        }
        else {
          piVar12 = piVar12 + 0x10;
          (*(code *)PTR_BIO_printf_006a7f38)(puVar7,&DAT_00635c74);
        }
        pcVar16 = pcVar16 + 1;
        if (pcVar16 == pcVar4) goto LAB_0042fa58;
      }
      pcVar16 = pcVar16 + 1;
      (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"%c");
    } while (pcVar16 != pcVar4);
  }
LAB_0042fa58:
  puVar15 = (undefined4 *)0x63ae04;
  (*(code *)PTR_BIO_printf_006a7f38)(puVar7);
  if (puStack_84 == *(undefined4 **)puVar9) {
    return 1;
  }
  puVar5 = puStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar7 = (undefined *)(*(code *)PTR_BUF_strdup_006a80dc)(&_gp);
  puVar8 = (undefined *)(*(code *)PTR_strchr_006aab34)(puVar7,0x2c);
  puVar9 = PTR_strchr_006aab34;
  if (puVar8 == (undefined *)0x0) {
    if (puVar5 != (undefined4 *)0x0) {
      uVar1 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
      puVar9 = PTR_ASN1_UTCTIME_set_string_006a8134;
      *puVar5 = uVar1;
      iVar2 = (*(code *)puVar9)(uVar1,puVar7);
      if (iVar2 == 0) goto LAB_0042fdc4;
    }
    iVar14 = 0;
    iVar2 = 0;
    uVar1 = 0xffffffff;
    goto LAB_0042fdec;
  }
  puVar6 = puVar8 + 1;
  *puVar8 = 0;
  puVar9 = (undefined *)(*(code *)puVar9)(puVar6,0x2c);
  if (puVar9 == (undefined *)0x0) {
    puVar8 = (undefined *)0x0;
  }
  else {
    puVar8 = puVar9 + 1;
    *puVar9 = 0;
  }
  if (puVar5 != (undefined4 *)0x0) {
    uVar1 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
    puVar9 = PTR_ASN1_UTCTIME_set_string_006a8134;
    *puVar5 = uVar1;
    iVar2 = (*(code *)puVar9)(uVar1,puVar7);
    if (iVar2 != 0) goto LAB_0042fbfc;
LAB_0042fdc4:
    pcVar4 = "invalid revocation date %s\n";
    puVar8 = puVar7;
    goto LAB_0042fd40;
  }
LAB_0042fbfc:
  iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"unspecified");
  if (iVar2 == 0) {
    uVar1 = 0;
    iVar14 = 0;
    iVar2 = 0;
LAB_0042fdec:
    if (puVar15 != (undefined4 *)0x0) {
      *puVar15 = uVar1;
    }
    puVar9 = PTR_CRYPTO_free_006a7f88;
    if (piVar13 == (int *)0x0) {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar14);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar7);
      uVar1 = 1;
      if (piVar12 != (int *)0x0) goto LAB_0042fea0;
    }
    else {
      *piVar13 = iVar14;
      (*(code *)puVar9)(puVar7);
      uVar1 = 1;
      if (piVar12 != (int *)0x0) {
        return 1;
      }
    }
LAB_0042fe18:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar2);
  }
  else {
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"keyCompromise");
    if (iVar2 == 0) {
      uVar1 = 1;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"CACompromise");
    if (iVar2 == 0) {
      uVar1 = 2;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"affiliationChanged");
    if (iVar2 == 0) {
      uVar1 = 3;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"superseded");
    if (iVar2 == 0) {
      uVar1 = 4;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"cessationOfOperation");
    if (iVar2 == 0) {
      uVar1 = 5;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"certificateHold");
    if (iVar2 == 0) {
      uVar1 = 6;
      iVar14 = 0;
      iVar2 = 0;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"removeFromCRL");
    if (iVar2 == 0) {
      iVar14 = 0;
      iVar2 = 0;
      uVar1 = 8;
      goto LAB_0042fdec;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"holdInstruction");
    if (iVar2 == 0) {
      if (puVar8 != (undefined *)0x0) {
        iVar2 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar8,0);
        if (iVar2 == 0) {
          pcVar4 = "invalid object identifier %s\n";
          goto LAB_0042fd40;
        }
        if (piVar12 == (int *)0x0) {
          iVar14 = 0;
          uVar1 = 6;
        }
        else {
          *piVar12 = iVar2;
          iVar14 = 0;
          uVar1 = 6;
        }
        goto LAB_0042fdec;
      }
      pcVar4 = "missing hold instruction\n";
LAB_0042ffe8:
      iVar14 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar4);
    }
    else {
      iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"keyTime");
      if (iVar2 == 0) {
        iVar2 = 9;
LAB_0042ff64:
        if (puVar8 == (undefined *)0x0) {
          pcVar4 = "missing compromised time\n";
          goto LAB_0042ffe8;
        }
        iVar14 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a813c)();
        iVar10 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(iVar14,puVar8);
        if (iVar10 != 0) {
          uVar1 = 2;
          if (iVar2 == 9) {
            uVar1 = 1;
          }
          iVar2 = 0;
          goto LAB_0042fdec;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"invalid compromised time %s\n",puVar8);
      }
      else {
        iVar2 = (*(code *)PTR_strcasecmp_006aab24)(puVar6,"CAkeyTime");
        if (iVar2 == 0) {
          iVar2 = 10;
          goto LAB_0042ff64;
        }
        pcVar4 = "invalid reason code %s\n";
        puVar8 = puVar6;
LAB_0042fd40:
        iVar14 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar4,puVar8);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar7);
    uVar1 = 0;
    if (piVar12 == (int *)0x0) {
      iVar2 = 0;
      goto LAB_0042fe18;
    }
  }
  if (piVar13 != (int *)0x0) {
    return uVar1;
  }
LAB_0042fea0:
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar14);
  return uVar1;
}

