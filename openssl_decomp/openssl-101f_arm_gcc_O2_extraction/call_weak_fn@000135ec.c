
void call_weak_fn(void)

{
  if (*(int *)(DAT_00013608 + 0x135fc + DAT_0001360c) == 0) {
    return;
  }
  (*(code *)PTR___gmon_start___0018a10c)();
  return;
}

