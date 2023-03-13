
void ** level_add_node(int param_1,void *param_2,void *param_3,int param_4)

{
  void **data;
  int iVar1;
  _STACK *p_Var2;
  
  data = (void **)CRYPTO_malloc(0xc,"pcy_node.c",0x75);
  if (data == (void **)0x0) {
    data = (void **)0x0;
  }
  else {
    *data = param_2;
    data[1] = param_3;
    data[2] = (void *)0x0;
    if (param_1 != 0) {
      iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)((int)param_2 + 4));
      if (iVar1 == 0x2ea) {
        if (*(int *)(param_1 + 8) != 0) goto LAB_081d1acf;
        *(void ***)(param_1 + 8) = data;
      }
      else {
        p_Var2 = *(_STACK **)(param_1 + 4);
        if (p_Var2 == (_STACK *)0x0) {
          p_Var2 = sk_new(node_cmp);
          *(_STACK **)(param_1 + 4) = p_Var2;
          if (p_Var2 == (_STACK *)0x0) goto LAB_081d1acf;
        }
        iVar1 = sk_push(p_Var2,data);
        if (iVar1 == 0) goto LAB_081d1acf;
      }
    }
    if (param_4 != 0) {
      p_Var2 = *(_STACK **)(param_4 + 8);
      if (p_Var2 == (_STACK *)0x0) {
        p_Var2 = sk_new_null();
        *(_STACK **)(param_4 + 8) = p_Var2;
        if (p_Var2 == (_STACK *)0x0) goto LAB_081d1acf;
      }
      iVar1 = sk_push(p_Var2,param_2);
      if (iVar1 == 0) {
LAB_081d1acf:
        CRYPTO_free(data);
        return (void **)0x0;
      }
    }
    if (param_3 != (void *)0x0) {
      *(int *)((int)param_3 + 8) = *(int *)((int)param_3 + 8) + 1;
    }
  }
  return data;
}

