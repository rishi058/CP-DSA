perform_operation() {
    # 1. Lowercase input & parse safely (Fixes BusyBox '?' error with [-])
    local op=$(grep -oE '\b(sum|difference|multiply|divide)\b' <<<"${1,,}" | head -n1)
    local nums=($(grep -oE '[-]?[0-9]+' <<<"$1"))

    # 2. Edge Case: Ensure we have an operator and 2 numbers
    [[ -z "$op" || ${#nums[@]} -lt 2 ]] && { echo "0"; return; }

    # 3. Calculate (Concise logic)
    case "$op" in
        sum)        echo $((${nums[0]} + ${nums[1]})) ;;
        difference) echo $((${nums[0]} - ${nums[1]})) ;;
        multiply)   echo $((${nums[0]} * ${nums[1]})) ;;
        divide)     [[ ${nums[1]} -eq 0 ]] && echo "0" || echo $((${nums[0]} / ${nums[1]})) ;;
    esac
}