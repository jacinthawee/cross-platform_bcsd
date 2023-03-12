
undefined4 * load_index(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  int local_128;
  undefined auStack_124 [256];
  int *local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar3 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar4 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  local_128 = -1;
  if (iVar4 == 0) {
    puVar8 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
    goto LAB_0045c2e4;
  }
  iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0x6c,3,param_1);
  if (iVar5 < 1) {
    (*(code *)PTR_perror_006aab88)(param_1);
    puVar8 = (undefined4 *)0x0;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to open \'%s\'\n",param_1);
  }
  else {
    iVar5 = (*(code *)PTR_TXT_DB_read_006a8cdc)(iVar4,6);
    if (iVar5 == 0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_124,0x100,"%s.attr",param_1);
      iVar6 = (*(code *)PTR_NCONF_new_006a7f58)(0);
      iVar7 = (*(code *)PTR_NCONF_load_006a7f5c)(iVar6,auStack_124,&local_128);
      iVar11 = iVar6;
      if (iVar7 < 1) {
        if (local_128 < 1) {
          iVar11 = 0;
          (*(code *)PTR_NCONF_free_006a7f6c)(iVar6);
          goto LAB_0045c238;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "error on line %ld of db attribute file \'%s\'\n",local_128,auStack_124);
      }
      else {
LAB_0045c238:
        puVar8 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"apps.c",0x731);
        if (puVar8 != (undefined4 *)0x0) {
          puVar8[1] = iVar5;
          if (param_2 == (undefined4 *)0x0) {
            *puVar8 = 1;
          }
          else {
            *puVar8 = *param_2;
          }
          if (iVar11 == 0) goto LAB_0045c2d4;
          pcVar9 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)(iVar11,0,"unique_subject");
          if (pcVar9 != (char *)0x0) {
            cVar1 = *pcVar9;
            if (cVar1 != 'N') {
              if (cVar1 < 'O') {
                if ((cVar1 != '0') && (cVar1 != 'F')) goto LAB_0045c2c0;
              }
              else if ((cVar1 != 'f') && (cVar1 != 'n')) {
LAB_0045c2c0:
                *puVar8 = 1;
                goto LAB_0045c2c4;
              }
            }
            *puVar8 = 0;
          }
LAB_0045c2c4:
          (*(code *)PTR_NCONF_free_006a7f6c)(iVar11);
          goto LAB_0045c2d4;
        }
        (*(code *)PTR_fwrite_006aab7c)("Out of memory\n",1,0xe,*(undefined4 *)PTR_stderr_006aac00);
        iVar6 = iVar11;
      }
      if (iVar6 != 0) {
        (*(code *)PTR_NCONF_free_006a7f6c)(iVar6);
      }
      puVar8 = (undefined4 *)0x0;
      (*(code *)PTR_TXT_DB_free_006a8ce0)(iVar5);
    }
  }
LAB_0045c2d4:
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar4);
LAB_0045c2e4:
  if (local_24 == *(int **)puVar2) {
    return puVar8;
  }
  piVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar8 = (undefined4 *)
           (*(code *)PTR_TXT_DB_create_index_006a8ce4)
                     (piVar10[1],3,0,index_serial_LHASH_HASH,index_serial_LHASH_COMP);
  if (puVar8 == (undefined4 *)0x0) {
    iVar4 = piVar10[1];
    pcVar9 = "error creating serial number index:(%ld,%ld,%ld)\n";
  }
  else {
    if ((*piVar10 == 0) ||
       (puVar8 = (undefined4 *)
                 (*(code *)PTR_TXT_DB_create_index_006a8ce4)
                           (piVar10[1],5,index_name_qual,index_name_LHASH_HASH,index_name_LHASH_COMP
                           ), puVar8 != (undefined4 *)0x0)) {
      return (undefined4 *)0x1;
    }
    iVar4 = piVar10[1];
    pcVar9 = "error creating name index:(%ld,%ld,%ld)\n";
  }
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,pcVar9,*(undefined4 *)(iVar4 + 0x10),
             *(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18));
  return puVar8;
}

