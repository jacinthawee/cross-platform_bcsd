
void obj_cmp_BSEARCH_CMP_FN(int *param_1,int *param_2)

{
  if (*(int *)(*param_1 + 0xc) != *(int *)(&DAT_00140f94 + *param_2 * 0x18)) {
    return;
  }
  (*(code *)PTR_memcmp_0018a06c)
            (*(undefined4 *)(*param_1 + 0x10),(&PTR_lvalues_00140f98)[*param_2 * 6]);
  return;
}

