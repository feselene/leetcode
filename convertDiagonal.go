func convert(s string, numRows int) string {
    if numRows == 1 || numRows >= len(s) {
        return s;
    }

    rows := make([]string, numRows)
    currentRow, direction := 0, -1

    for _, char := range s {
        rows[currentRow] += string(char)

        if currentRow == 0 || currentRow == numRows - 1 {
            direction *= -1
        }

        currentRow += direction
    }

    result := ""
    for _, row := range rows {
        result += row
    }

    return result
}