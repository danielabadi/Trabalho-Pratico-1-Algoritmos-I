EXEC=$1
TMP_OUT=tp1.out

echo "Testes"
for i in {1..5..1}; do
  testname=$(printf "EX%d" $i)
  $EXEC testcases/$testname > $TMP_OUT
  if ! diff -qwB testcases/$testname.out $TMP_OUT &>/dev/null; then
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done


rm $TMP_OUT
