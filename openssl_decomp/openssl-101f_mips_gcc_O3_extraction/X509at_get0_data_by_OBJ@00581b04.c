
void * X509at_get0_data_by_OBJ(stack_st_X509_ATTRIBUTE *x,ASN1_OBJECT *obj,int lastpos,int type)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (void *)0x0;
  }
  iVar1 = lastpos + 1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)();
  if (iVar2 <= iVar1) {
    return (void *)0x0;
  }
  while( true ) {
    puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(x,iVar1);
    iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar3,obj);
    if (iVar4 == 0) break;
    iVar1 = iVar1 + 1;
    if (iVar2 == iVar1) {
      return (void *)0x0;
    }
  }
  if (iVar1 == -1) {
    return (void *)0x0;
  }
  if (lastpos < -1) {
    iVar2 = iVar1 + 1;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(x);
    if (iVar2 < iVar4) {
      do {
        puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(x,iVar2);
        iVar5 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar3,obj);
        if (iVar5 == 0) {
          if (iVar2 != -1) {
            return (void *)0x0;
          }
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar4 != iVar2);
    }
  }
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(x);
  if ((iVar1 < iVar2) && (-1 < iVar1)) {
    iVar1 = (*(code *)PTR_sk_value_006a7f24)(x,iVar1);
    if (lastpos < -2) goto LAB_00581c00;
    if (iVar1 == 0) {
      return (void *)0x0;
    }
LAB_00581cfc:
    if (*(int *)(iVar1 + 4) == 0) {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar1 + 8));
      if (iVar2 < 1) {
        return (void *)0x0;
      }
      if (*(int *)(iVar1 + 4) == 0) {
        iVar1 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar1 + 8),0);
      }
      else {
        iVar1 = *(int *)(iVar1 + 8);
      }
      goto joined_r0x00581d34;
    }
  }
  else {
    iVar1 = 0;
    if (-3 < lastpos) {
      return (void *)0x0;
    }
LAB_00581c00:
    if (*(int *)(iVar1 + 4) == 0) {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar1 + 8));
      if (iVar2 != 1) {
        return (void *)0x0;
      }
      goto LAB_00581cfc;
    }
  }
  iVar1 = *(int *)(iVar1 + 8);
joined_r0x00581d34:
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(iVar1);
    if (type == iVar2) {
      return *(void **)(iVar1 + 4);
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x8b,0x7a,"x509_att.c",0x15b);
  }
  return (void *)0x0;
}

