
$romans = @('M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I')
$decimals = @(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
$res = ""
$value = 1234
$i = 0

while ($value > 0) {
    if (value - $decimals[$i] >= 0) {
        $res += $romans[$i]
        $value -= $decimals[$i]
    } else {
        $i += 1
    }
}

Write-Host $res
