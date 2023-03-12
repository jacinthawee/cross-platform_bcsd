
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
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  int iVar16;
  code *pcVar17;
  undefined auStack_a0 [28];
  int *piStack_84;
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
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_80 = &local_44;
  local_50 = &_gp;
  local_44 = (undefined *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_38 = (int *)0x0;
  local_34 = 0;
  local_30 = (int *)0x0;
  local_2c = *(undefined **)PTR___stack_chk_guard_006a9ae8;
  piVar11 = param_4;
  uVar1 = (*(code *)PTR_X509_get_subject_name_006a6f00)();
  piVar9 = (int *)0x0;
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
        puVar14 = *(undefined4 **)(local_50 + -0x7fa4);
        piVar11 = local_30;
        (**(code **)(local_50 + -0x7fa8))
                  (*puVar14,"Adding Entry with serial number %s to DB for %s\n",local_38);
        local_44 = (undefined *)(**(code **)(local_50 + -0x7dd8))(2,&DAT_0063526c,0x93b);
        piVar10 = *(int **)(*(int *)(*param_1 + 0x10) + 4);
        local_40 = (**(code **)(local_50 + -0x7dd8))(*piVar10 + 1,&DAT_0063526c,0x93e);
        (**(code **)(local_50 + -0x52f4))(local_40,piVar10[2],*piVar10);
        piVar9 = (int *)0x945;
        pcVar17 = *(code **)(local_50 + -0x7dd8);
        *(undefined *)(local_40 + *piVar10) = 0;
        local_3c = 0;
        local_34 = (*pcVar17)(8,&DAT_0063526c);
        if (((local_44 != (undefined *)0x0) && (local_40 != 0)) && (local_34 != 0)) {
          (**(code **)(local_50 + -0x7e7c))(local_34,"unknown",8);
          piVar9 = (int *)0x953;
          *local_44 = 0x56;
          pcVar17 = *(code **)(local_50 + -0x7dd8);
          local_44[1] = 0;
          puVar5 = (undefined4 *)(*pcVar17)(0x1c,&DAT_0063526c);
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
              (**(code **)(local_50 + -0x7fa8))(*puVar14,"failed to update database\n");
              uStack_70 = 0xffffffff;
              piVar9 = *(int **)(*(int *)(param_2 + 4) + 0x10);
              (**(code **)(local_50 + -0x7fa8))(*puVar14,"TXT_DB error number %ld\n");
            }
            else {
              piVar9 = param_3;
              piVar11 = param_4;
              uStack_70 = do_revoke(param_1,param_2);
            }
            goto LAB_0042f704;
          }
        }
        uStack_70 = 0xffffffff;
        (**(code **)(local_50 + -0x7fa8))(*puVar14,"Memory allocation failure\n");
      }
      else {
        iVar2 = (**(code **)(local_50 + -0x7dbc))(ppuStack_80,ppcVar3);
        if (iVar2 == 0) {
          param_1 = (int *)0x52;
          if (**ppcVar3 != 'R') {
            puVar14 = *(undefined4 **)(local_50 + -0x7fa4);
            piVar9 = (int *)ppcVar3[3];
            (**(code **)(local_50 + -0x7fa8))(*puVar14,"Revoking Certificate %s.\n");
            pcVar4 = (char *)make_revocation_str(param_3,param_4);
            if (pcVar4 == (char *)0x0) {
              uStack_70 = 0xffffffff;
              (**(code **)(local_50 + -0x7fa8))(*puVar14,"Error in revocation arguments\n");
            }
            else {
              uStack_70 = 1;
              **ppcVar3 = 'R';
              (*ppcVar3)[1] = '\0';
              ppcVar3[2] = pcVar4;
            }
            goto LAB_0042f704;
          }
          pcVar17 = *(code **)(local_50 + -0x7fa8);
          pcVar4 = "ERROR:Already revoked, serial number %s\n";
          piVar9 = local_38;
        }
        else {
          pcVar17 = *(code **)(local_50 + -0x7fa8);
          pcVar4 = "ERROR:name does not match %s\n";
          piVar9 = local_30;
        }
        uStack_70 = 0xffffffff;
        (*pcVar17)(**(undefined4 **)(local_50 + -0x7fa4),pcVar4);
      }
    }
  }
LAB_0042f704:
  ppuStack_7c = &local_2c;
  puVar7 = local_50;
  do {
    if (*ppuStack_80 != (undefined *)0x0) {
      (**(code **)(puVar7 + -0x7f58))();
      puVar7 = local_50;
    }
    ppuStack_80 = ppuStack_80 + 1;
  } while (ppuStack_80 != ppuStack_7c);
  if (local_2c == *(undefined **)puStack_78) {
    return uStack_70;
  }
  pcStack_64 = old_entry_print;
  puVar13 = local_2c;
  (**(code **)(puVar7 + -0x5330))();
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  piStack_84 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piStack_74 = param_1;
  piStack_6c = param_3;
  piStack_68 = param_4;
  iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)();
  puVar6 = auStack_a0;
  iVar2 = 0x16 - iVar2;
  puVar8 = puVar6;
  if (0 < iVar2) {
    puVar6 = (undefined *)(*(code *)PTR_memset_006a99f4)(puVar6,0x20,iVar2);
    puVar8 = puVar6 + iVar2;
  }
  puVar8[1] = 0;
  *puVar8 = 0x3a;
  (*(code *)PTR_BIO_puts_006a6f58)(puVar13,puVar6);
  piVar10 = (int *)piVar9[1];
  if (piVar10 == (int *)&DAT_00000013) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"PRINTABLE:\'");
  }
  else if (piVar10 == (int *)&DAT_00000014) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"T61STRING:\'");
  }
  else if (piVar10 == (int *)&DAT_00000016) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"IA5STRING:\'");
  }
  else if (piVar10 == (int *)0x1c) {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"UNIVERSALSTRING:\'");
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"ASN.1 %2d:\'");
  }
  pcVar15 = (char *)piVar9[2];
  pcVar4 = pcVar15 + *piVar9;
  if (0 < *piVar9) {
    do {
      while (piVar10 = (int *)(int)*pcVar15, ((uint)(piVar10 + -8) & 0xff) < 0x5f) {
        pcVar15 = pcVar15 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"%c");
        if (pcVar15 == pcVar4) goto LAB_0042fb74;
      }
      if ((int)piVar10 < 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(puVar13,"\\0x%02X");
      }
      else {
        piVar10 = piVar10 + 0x10;
        (*(code *)PTR_BIO_printf_006a6e38)(puVar13,&DAT_006353b4);
      }
      pcVar15 = pcVar15 + 1;
    } while (pcVar15 != pcVar4);
  }
LAB_0042fb74:
  puVar14 = (undefined4 *)0x63a5e4;
  (*(code *)PTR_BIO_printf_006a6e38)(puVar13);
  if (piStack_84 == *(int **)puVar7) {
    return 1;
  }
  piVar9 = piStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar7 = (undefined *)(*(code *)PTR_BUF_strdup_006a6fdc)(&_gp);
  if (puVar7 == (undefined *)0x0) {
    iVar2 = 0;
    iVar16 = 0;
    uVar1 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
    goto joined_r0x00430004;
  }
  puVar8 = (undefined *)(*(code *)PTR_strchr_006a9a28)(puVar7,0x2c);
  puVar13 = PTR_strchr_006a9a28;
  if (puVar8 == (undefined *)0x0) {
    puVar13 = (undefined *)0x0;
    if (piVar9 != (int *)0x0) {
      puVar6 = (undefined *)0x0;
      goto LAB_0042fcf8;
    }
LAB_0042ff44:
    iVar2 = 0;
    iVar16 = 0;
    uVar1 = 0xffffffff;
    goto LAB_0042ff50;
  }
  puVar6 = puVar8 + 1;
  *puVar8 = 0;
  puVar8 = (undefined *)(*(code *)puVar13)(puVar6,0x2c);
  if (puVar8 == (undefined *)0x0) {
    puVar13 = (undefined *)0x0;
  }
  else {
    puVar13 = puVar8 + 1;
    *puVar8 = 0;
  }
  if (piVar9 != (int *)0x0) {
LAB_0042fcf8:
    iVar2 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
    *piVar9 = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ASN1_UTCTIME_set_string_006a7034)(iVar2,puVar7);
      if (iVar2 != 0) {
        if (puVar6 == (undefined *)0x0) goto LAB_0042ff44;
        goto LAB_0042fd30;
      }
      pcVar4 = "invalid revocation date %s\n";
      puVar6 = puVar7;
LAB_0042fe70:
      iVar2 = 0;
      iVar16 = 0;
      uVar1 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar4,puVar6);
      goto LAB_0042fe8c;
    }
    pcVar4 = "memory allocation failure\n";
    goto LAB_0042ffc0;
  }
LAB_0042fd30:
  iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"unspecified");
  if (iVar2 == 0) {
    uVar1 = 0;
    iVar2 = 0;
    iVar16 = 0;
LAB_0042ff50:
    if (puVar14 != (undefined4 *)0x0) {
      *puVar14 = uVar1;
    }
    if (piVar11 == (int *)0x0) {
      uVar1 = 1;
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar2);
    }
    else {
      *piVar11 = iVar2;
      uVar1 = 1;
    }
  }
  else {
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"keyCompromise");
    if (iVar2 == 0) {
      uVar1 = 1;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"CACompromise");
    if (iVar2 == 0) {
      uVar1 = 2;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"affiliationChanged");
    if (iVar2 == 0) {
      uVar1 = 3;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"superseded");
    if (iVar2 == 0) {
      uVar1 = 4;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"cessationOfOperation");
    if (iVar2 == 0) {
      uVar1 = 5;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"certificateHold");
    if (iVar2 == 0) {
      uVar1 = 6;
      iVar2 = 0;
      iVar16 = 0;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"removeFromCRL");
    if (iVar2 == 0) {
      iVar2 = 0;
      iVar16 = 0;
      uVar1 = 8;
      goto LAB_0042ff50;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"holdInstruction");
    if (iVar2 == 0) {
      if (puVar13 == (undefined *)0x0) {
        pcVar4 = "missing hold instruction\n";
        goto LAB_0042ffc0;
      }
      iVar16 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar13,0);
      if (iVar16 != 0) {
        if (piVar10 == (int *)0x0) {
          iVar2 = 0;
          uVar1 = 6;
        }
        else {
          *piVar10 = iVar16;
          iVar2 = 0;
          uVar1 = 6;
        }
        goto LAB_0042ff50;
      }
      iVar2 = 0;
      uVar1 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid object identifier %s\n",puVar13);
    }
    else {
      iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"keyTime");
      if (iVar2 == 0) {
        iVar12 = 9;
      }
      else {
        iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(puVar6,"CAkeyTime");
        if (iVar2 != 0) {
          pcVar4 = "invalid reason code %s\n";
          goto LAB_0042fe70;
        }
        iVar12 = 10;
      }
      if (puVar13 == (undefined *)0x0) {
        pcVar4 = "missing compromised time\n";
LAB_0042ffc0:
        iVar2 = 0;
        iVar16 = 0;
        uVar1 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar4);
      }
      else {
        iVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a703c)();
        if (iVar2 == 0) {
          iVar16 = 0;
          uVar1 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"memory allocation failure\n");
        }
        else {
          iVar16 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a6ffc)(iVar2,puVar13);
          if (iVar16 != 0) {
            uVar1 = 2;
            iVar16 = 0;
            if (iVar12 == 9) {
              uVar1 = 1;
            }
            goto LAB_0042ff50;
          }
          iVar16 = 0;
          uVar1 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"invalid compromised time %s\n",puVar13);
        }
      }
    }
  }
LAB_0042fe8c:
  (*(code *)PTR_CRYPTO_free_006a6e88)(puVar7);
joined_r0x00430004:
  if (piVar10 == (int *)0x0) {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar16);
  }
  if (piVar11 == (int *)0x0) {
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iVar2);
    return uVar1;
  }
  return uVar1;
}

